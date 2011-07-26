//
//  G6PayVideoOfferView.h
//  YouTube
//
//  Created by RyanBertrand on 7/13/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>

@class G6PayAppIconView;
@class G6PayVideoOffer;
@class G6PayAdManager;
@interface G6PayOfferView : UIViewController {
	G6PayVideoOffer *offer;
    G6PayAdManager *adManager;
	
	//Video
	IBOutlet UIView *videoView;
	IBOutlet UILabel *appWillResumeInLbl;
	IBOutlet UIButton *spipVideoBtn;
	IBOutlet UIActivityIndicatorView *loader;
	MPMoviePlayerController *videoPlayer;
	NSTimer *videoTimer;
	NSInteger videoTimeLeft;
	NSURL *previousVideoURL;
	BOOL videoAdWasSkipped;
	
	//App Details
	IBOutlet G6PayAppIconView *appIconImg;
	IBOutlet UILabel *appNameLbl;
	IBOutlet UIButton *cancelBtn;
	IBOutlet UIButton *downloadBtn;
	IBOutlet UIImageView *logoImage;
	IBOutlet UIImageView *backgroundImage;
	
}
@property(nonatomic, retain)G6PayVideoOffer *offer;
@property(nonatomic, retain)MPMoviePlayerController *videoPlayer;
@property(nonatomic, retain)NSTimer *videoTimer;
@property(nonatomic, retain)G6PayAdManager *adManager;
@property(nonatomic, retain)NSURL *previousVideoURL;

-(id)initWithG6PayAdManager:(G6PayAdManager *)manager videoOffer:(G6PayVideoOffer *)videoOffer;
+(G6PayOfferView *)videoAdPlayer;

-(void)loadVideoAd;

-(IBAction)skipVideoAd;
-(IBAction)cancelAppOffer;
-(IBAction)downloadAppOffer;

@end
