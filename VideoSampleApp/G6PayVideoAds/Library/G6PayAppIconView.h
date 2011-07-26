//
//  AppIconView.h
//  YouTube
//
//  Created by RyanBertrand on 7/14/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol G6PayAppIconViewDelegate <NSObject>

-(void)appIconViewDidFinishLoadingImage:(BOOL)success;

@end


@interface G6PayAppIconView : UIView {
	
	NSURLConnection* connection;
	NSMutableData* data;
	
	id <G6PayAppIconViewDelegate>delegate;
}
@property(nonatomic, retain)id <G6PayAppIconViewDelegate>delegate;

- (void)loadImageFromURL:(NSURL*)url;
- (UIImage*) image;

@end