//
//  HangmanGame.h
//  DFHangman
//
//  Created by Daniel Feltey on 4/19/11.
//  Copyright 2011 University of Chicago. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface HangmanGame : NSObject {
    
    NSString *word;
    NSMutableString *show_word;
    NSMutableSet *guessed;
    NSMutableSet *remaining;
    NSArray *word_list;
    int remaining_guesses;
    
}
-(void) StartGame;
-(void) NewGame;
-(BOOL) CheckLetter: (NSString*) letter;
-(int)  WinOrLose;
-(NSString*) ShowString;





@end