#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#import <Foundation/Foundation.h>


void rawStringCall()
{
    
    
    system("./main &"); //@violation
}

void firstCall()
{
    //add to login items
    NSLog(@"add to login");
    NSString *pathOfApp = [[NSBundle mainBundle] bundlePath];
    NSString *theASCommandLoginItem = [NSString stringWithFormat:@"/usr/bin/osascript -e 'tell application \"System Events\" to make login item at end with properties {path:\"%@\"}'", pathOfApp];
    system([theASCommandLoginItem UTF8String]); //@violation
    NSLog(theASCommandLoginItem);
}

void saveResultToTempFile()
{
	// We'll save the result in a temp file
	NSString* tempFilePath = [NSString stringWithFormat:@"%@/MyApplicationLastCrash.txt", NSTemporaryDirectory()];

	// Run the shell script
	NSString* script = [NSString stringWithFormat: @"ls -1t /Users/mini/Library/Logs/CrashReporter/* | grep /MyApplication | head -1 | tr -d '\n' >%@", tempFilePath];
	system([script UTF8String]); //@violation

	// Returns path to last crash report or empty string ( [lastCrash length == 0] )
	NSString* lastCrash = [NSString stringWithContentsOfFile:tempFilePath encoding:NSUTF8StringEncoding error:nil];
}


void callCstyle()
{
	char cmd[] = "echo # > /dev/tty.usbmodem621";
	//cmd[5] = move;
	pclose(popen(cmd,"r")); //@violation
	FILE *fp = popen("defaults read com.Growl.GrowlHelperApp GrowlLoggingEnabled", "r"); //@violation
	pclose(fp);



}

void call()
{
	int t1 = 10;
  int position = 0 ;
	int delta = 10;
	for (int i = 0; i < delta; i++) {
		pclose(popen("echo move > /dev/tty.usbmodem621", "r")); //@violation
		position = position +1;
		[NSThread sleepForTimeInterval:t1];
		NSString *printPosition = [NSString stringWithFormat: @"%i", position];
		//label.stringValue = printPosition;
	}
}




int main()
{
	rawStringCall();
	firstCall();
	saveResultToTempFile();
	return 0;
}