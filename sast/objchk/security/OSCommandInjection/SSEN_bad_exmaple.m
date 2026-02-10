 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 #define MAX 100
 int main(intargc, char*argv[])
  {
     char arg[MAX-4];
     char command[MAX] = "cat ";
     fgets(arg, MAX-4, stdin);
     strncat(command, arg, MAX-4);
     system(command); //@violation
     return 0;
  }





@interface RawStringtoURL : NSObject
- (BOOL)textField:(UITextField *)theTextField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;

@end


@implementation RawStringtoURL
- (BOOL)textField:(UITextField *)theTextField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string {
    NSString *newText = [theTextField.text stringByReplacingCharactersInRange:range withString:string];
    system(newText); //@will-violation



}
@end

