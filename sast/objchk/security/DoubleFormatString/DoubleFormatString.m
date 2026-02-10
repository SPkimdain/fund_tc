#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import <AppKit/AppKit.h>
//for OSX objc
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
void badCase()
{
    NSAlert *alert;
	alert = [NSAlert alertWithMessageText:@"Certificate Import Succeeded" //@violation
    defaultButton:@"OK"
    alternateButton:nil
    otherButton:nil
    informativeTextWithFormat:[NSString stringWithFormat: 
       @"The imported certificate \"%@\" has been selected in the certificate pop-up.",
       @"stringWithString"]];
 
	[alert setAlertStyle:NSInformationalAlertStyle];
	[alert runModal];
}
void properCase()
{
    NSAlert *alert;
	alert = [NSAlert alertWithMessageText:@"Certificate Import Succeeded"
    defaultButton:@"OK"
    alternateButton:nil
    otherButton:nil
                informativeTextWithFormat:@"The imported certificate \"%@\" has been selected in the certificate pop-up.",@"selected cert"];
    [alert setAlertStyle:NSInformationalAlertStyle];
	[alert runModal];
    
}