//
//  HangmanGame.h
//  DFHangman
//
//  Created by Daniel Feltey on 4/19/11.
//  Copyright 2011 University of Chicago. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface HangmanGame : NSObject {
    
    NSString *word;//keep
    NSMutableString *show_word;//NSMutableArray...
    NSMutableSet *guessed; //remove
    NSMutableSet *remaining; //keep
    NSArray *word_list; //keep
    int remaining_guesses;//keep
    
// 
    
}
-(void) StartGame;
-(void) NewGame;
-(BOOL) CheckLetter: (NSString*) letter;
-(int)  WinOrLose;
-(NSString*) ShowString;





@end