//
//  ImExController.h
//  ImmExample
//
//  Created by Fritz Anderson on 4/7/11.
//  Copyright 2011 Trustees of the University of Chicago. All rights reserved.
//

//	This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported license.
//	If you use this work (use must be consistent with the license), include the following language
//	in a user-accessible view, either in the application itself; in a panel in a Settings bundle identified
//	with your work; or in distribution labeling (such as package copy or App Store descriptions) that must
//	inevitably be seen by the end user:
///////////////////////////////////////////
//	Portions are copyright by the University of Chicago, and licensed under the Creative Commons
//	Attribution-NonCommercial-ShareAlike 3.0 Unported license. For details, see 
//	http://creativecommons.org/licenses/by-nc-sa/3.0/ and links therefrom.
//	The University of Chicago has provided its work on an "AS-IS" basis, and its work comes with
//	ABSOLUTELY NO WARRANTY, INCLUDING THOSE OF MERCHANTABILITY OR FITNESS FOR ANY PURPOSE.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**	Abstract superclass of the embedded view controllers.
 
 Note well that ImExController is \em not a subclass of UIViewController.
 UIKit does not like having more than one UIViewController active in a window. This
 is okay, because other objects can link up with NIB objects.
 
 ImExController relies on there being a NIB file in the main bundle with
 a base name equal to the name of the ImExController being instantiated,
 and of course the suffix \c .nib. init will assert if such a NIB cannot
 be loaded.
 */

@interface ImExController : NSObject {
    
}

///	The view this object controls.
@property(nonatomic, retain) IBOutlet UIView *	view;

/**	Designated initializer for ImExController.
 Subclasses \em must call this method on super. It loads the corresponding NIB,
 which must have the same base name as the subclass itself. Once the NIB is loaded,
 viewDidLoad is called for the subclass to finish its initialization.
 \throws Asserts if a NIB with the same name as the class is not found.
 */
- (id) init;

/**	Notify the ImExController that its NIB has been loaded.
 Subclassers should override this method to initialize the view. 
 */
- (void) viewDidLoad;

@end
