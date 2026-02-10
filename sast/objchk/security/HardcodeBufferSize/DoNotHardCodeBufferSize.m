//
//  DoNotHardCodeBufferSize.m
//  temp
//
//  Created by PADEV2 on 2015. 11. 23..
//  Copyright © 2015년 PADEV2. All rights reserved.
//

#import <Foundation/Foundation.h>
#define BUF_SIZE 1024



int temp( int argc, char** argv)
{
    
    

    char cstring[40] ;//@violation
    int index = 50;
    char temp[index];
    

    scanf("%s",cstring);
    
    NSString *inputString = [NSString stringWithCString:cstring encoding:1];
    
    NSLog(@"You entered the word '%@'", inputString);
    
    return 0;
    
}


int temp2(int argc , char ** argv)
{
    NSLog(@"Please enter a word.");
    

    char cstring[BUF_SIZE];
    

    scanf("%s",cstring);

    NSString *inputString = [NSString stringWithCString:cstring encoding:1];
    
    NSLog(@"You entered the word '%@'", inputString);
    
    return 0;

}