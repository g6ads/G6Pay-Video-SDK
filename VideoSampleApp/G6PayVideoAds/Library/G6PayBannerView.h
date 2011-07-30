//
//  G6PayBannerView.h
//  YouTube
//
//  Created by sylvia bertrand on 7/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "G6PayAdManager.h"
#import "G6PayAppIconView.h"

typedef enum G6PayBannerContentSize{
    G6PayBannerContentSizeIdentifierPortrait = 0,
    G6PayBannerContentSizeIdentifierLanscape = 1
}G6PayBannerContentSize;

@class G6PayVideoOffer;
@interface G6PayBannerView : UIView
{
    G6PayVideoOffer *offer;
	G6PayAdManager *videoManager;
	G6PayAppIconView *appIcon;
	
	BOOL isLoaded;
}
@property(nonatomic, retain)G6PayVideoOffer *offer;
@property(nonatomic, retain)G6PayAdManager *videoManager;
@property(nonatomic, assign)BOOL isLoaded;

-(id)initWithVideoAdManager:(G6PayAdManager *)themanager contentSize:(G6PayBannerContentSize)size;

@end


