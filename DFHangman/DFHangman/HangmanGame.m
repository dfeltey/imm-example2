//
//  HangmanGame.m
//  DFHangman
//
//  Created by Daniel Feltey on 4/19/11.
//  Copyright 2011 University of Chicago. All rights reserved.
//

#import "HangmanGame.h"
#import <stdlib.h>
#import <time.h>

@implementation HangmanGame

-(void) StartGame
{
    srandom((unsigned) time(NULL));
    NSString *all_words = [[NSString alloc] initWithContentsOfFile:@"words"];
    word_list = [all_words componentsSeparatedByString:@"\n"];
    unsigned long num_words = [word_list count];
    
    word = [word_list objectAtIndex:random()%num_words];
    
    guessed = [NSMutableSet set];
    remaining =[NSMutableSet set];
    for (int i=0; i< [word length]; i++)
    {
        [remaining addObject:[NSString stringWithCharacters:[word characterAtIndex:i] length:1]];
    }
    
    
    
    remaining_guesses = 6;
    
}

-(void) NewGame
{
    unsigned long num_words = [word_list count];
    word = [word_list objectAtIndex:random()%num_words];
    remaining_guesses = 6;
    guessed = [NSMutableSet set];
    remaining =[NSMutableSet set];
    for (int i=0; i< [word length]; i++)
    {
        [remaining addObject:[NSString stringWithCharacters:[word characterAtIndex:i] length:1]];
    }
    
}

-(BOOL) CheckLetter:(NSString *)letter
{
    if([word rangeOfString:letter].location!=NSNotFound)
    {
        [remaining removeObject:letter];
        [guessed    addObject:letter];
        return YES;
    }
    else
    {
        remaining_guesses--;
        [guessed addObject:letter];
        return NO;
    }
    
}

-(int) WinOrLose
{
    if ([remaining count] == 0)
        return 1;
    else if(remaining_guesses == 0)
        return  -1;
    else
        return 0;
}

@end
