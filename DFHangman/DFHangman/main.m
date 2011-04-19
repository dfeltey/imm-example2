//
//  main.m
//  DFHangman
//
//  Created by Daniel Feltey on 4/19/11.
//  Copyright 2011 University of Chicago. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HangmanGame.h"

int main (int argc, const char * argv[])
{

    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    HangmanGame *game = [[HangmanGame alloc] init];
    char *string[2];
    NSString *letter;
    
    [game StartGame];
    while (![game WinOrLose])
    {
        NSLog(@"Enter a letter: ");
        scanf("%s",&string);
        letter = [NSString stringWithCString: string];
        [game CheckLetter:letter];
        NSLog(@"%@",[game ShowString]);
        
    }
    if ([game WinOrLose] == -1)
        NSLog(@"You Lose.\n");
    else
        NSLog(@"You Win!\n");
    
    
    [game release];
    [pool drain];
    return 0;
}

