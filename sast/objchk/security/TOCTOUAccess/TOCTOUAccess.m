#import <Foundation/Foundation.h>
#include <sys/stat.h>

@interface tempFileHandeler : NSObject
-(NSString *) properGettmpFile;
-(NSString *) improperGettmpFile;
@end

void fopenAction(double ** avgFeatureVect)
{
	FILE *fid200;
	fid200 = fopen ( "Length200Vector.txt" , "w" ); //@violation
	if (fid200 == NULL)
	    perror("Error opening Length200Vector.txt");
	for (int n = 0; n<200; n++) {
	    if (n == 0) {
	        fprintf (fid200, "%f", avgFeatureVect[0][n]);
	    }
	    else {
	    fprintf (fid200, ", %f", avgFeatureVect[0][n]);
	    }
	}
	fprintf (fid200, "\n");
	fclose(fid200);
}

void chmod_statAction()
{
	const char path[] = "hardcoded/path";

	/* Get the current mode. */
	struct stat buf;
	int error = stat(path, &buf); //@violation
	/* check and handle error */

	/* Make the file user-executable. */
	mode_t mode = buf.st_mode;
	mode |= S_IXUSR;
	error = chmod(path, mode); //@violation
	/* check and handle error */
}

@implementation tempFileHandeler
- (NSString *) properGettmpFile {
    NSString *tempFileTemplate = [NSTemporaryDirectory()
        stringByAppendingPathComponent:@"recording-XXXXXX.caf"];

    const char *tempFileTemplateCString =
        [tempFileTemplate fileSystemRepresentation];

    char *tempFileNameCString = (char *)malloc(strlen(tempFileTemplateCString) + 1);
    strcpy(tempFileNameCString, tempFileTemplateCString);
    int fileDescriptor = mkstemps(tempFileNameCString, 4);

    // no need to keep it open
    close(fileDescriptor);

    if (fileDescriptor == -1) {
        NSLog(@"Error while creating tmp file");
        return nil;
    }

    NSString *tempFileName = [[NSFileManager defaultManager] stringWithFileSystemRepresentation:tempFileNameCString length:strlen(tempFileNameCString)]; 

    free(tempFileNameCString);

    return tempFileName;
}

- (NSString *)improperGettmpFile {
    // Construct full-path template by prepending tmp directory path to filename template
    NSString *tempFilePathTemplate = [NSString pathWithComponents:@[NSTemporaryDirectory(), @"MyAppTemp.XXXXXX"]];
    
    // Convert template to ASCII for use by C library functions
    const char* tempFilePathTemplateASCII = [tempFilePathTemplate cStringUsingEncoding:NSASCIIStringEncoding];
    
    // Copy template to temporary buffer so it can be modified in place
    char *tempFilePathASCII = calloc(strlen(tempFilePathTemplateASCII) + 1, 1);
    strcpy(tempFilePathASCII, tempFilePathTemplateASCII);
    
    // Call mktemp() to replace the "XXXXXX" in the template with something unique
    NSString *tempFilePath = tempFilePathTemplate;
    if (mktemp(tempFilePathASCII)) { //@violation
        tempFilePath = [NSString stringWithCString:tempFilePathASCII encoding:NSASCIIStringEncoding];
    }
    
    // Free the temporary buffer
    free(tempFilePathASCII);
    
    return tempFilePath;
}

@end


void foo(char* file)
{
  if(!access(file, W_OK)){
    f = fopen(file, "w+"); //@violation
    operate(f);
  }
  else{
    fprintf(stderr, "Unable to open file %s.\n", file);
  }
}