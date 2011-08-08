//
//  G6Pay.h
//  YouTube
//
//  Created by RyanBertrand on 7/13/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "G6PayOfferView.h"

typedef enum G6PayConnectionType {
	G6PayConnectionOffers = 0,
	G6PayConnectionVideoCompletion = 1,
	G6PayConnectionDownloadingVideo = 2
	
}G6PayConnectionType;

typedef enum G6PayVideoCacheType {
	G6PayVideoOfferPreload = 1,//This will preload the video and then once it is downloaded it will call delegate with offer
	G6PayVideoOfferLiveStream = 2
}G6PayVideoCacheType;

@interface G6PayVideoOffer : NSObject
{
	NSString *appName;
	NSString *iconURL;
	NSString *videoURL;
	NSString *appStoreURL;
	NSString *signature;
	BOOL allowSkip;
	BOOL active;
	NSString *localVideoURL;
	NSString *virtualCurrencyName;
}

@property(nonatomic, retain)NSString *appName;
@property(nonatomic, retain)NSString *iconURL;
@property(nonatomic, retain)NSString *videoURL;
@property(nonatomic, retain)NSString *appStoreURL;
@property(nonatomic, retain)NSString *signature;
@property(nonatomic, assign)BOOL allowSkip;
@property(nonatomic, assign)BOOL active;
@property(nonatomic, retain)NSString *localVideoURL;
@property(nonatomic, retain)NSString *virtualCurrencyName;

+(G6PayVideoOffer *)offerWithContents:(NSDictionary*)contents;
+(NSString *)getTextForNode:(NSString *)node inDictionary:(NSDictionary *)dictionary;

@end

@protocol G6PayAdManagerDelegate <NSObject>
-(void)g6VideoAdsReadyInSpace:(NSString *)spaceID;
-(void)g6VideoAdsNotReadyInSpace:(NSString *)spaceID;
-(void)g6VideoNoVideoFillInSpace:(NSString *)spaceID;
-(void)g6VideoAdDidEndTakeover;
-(void)g6VideoAdIsAlreadyPlaying;
@end


@class G6PayURLConnection;
@interface G6PayAdManager : NSObject <NSXMLParserDelegate>{
	G6PayURLConnection *connection;
	NSMutableData *data;
    
    //Parser
	NSXMLParser * offerParser;
    NSMutableDictionary *offerParserItem;
    NSString *currentElement;
	NSMutableString *currentAppName, *currentIconURL, *currentVideoURL, *currentAppStoreURL, *currentAllowSkip, *currentActive, *currentSignature, *currentVirtualCurrencyName;
    
	NSMutableArray *cachedOffers;
	id <G6PayAdManagerDelegate>delegate;
	
    //G6Pay App ID
    NSString *g6PayAppID;
    
	//Presitial Space ID
	NSString *prestitialSpaceID;
	
	//Video Load Policy
	G6PayVideoCacheType *videoLoadType;
	
	//Current Downloading Video for Offer
	G6PayVideoOffer *offerCurrentlyDownloading;
	
	
	BOOL statusBarWasHidden;
	
	UIInterfaceOrientation videoOrientation;
}
@property (nonatomic, retain) G6PayURLConnection *connection;
@property (nonatomic, retain) NSMutableData* data;
@property (nonatomic, assign) id <G6PayAdManagerDelegate>delegate;
@property (nonatomic, retain) NSMutableArray *cachedOffers;
@property (nonatomic, retain) NSString *prestitialSpaceID;
@property (nonatomic, assign) G6PayVideoCacheType *videoLoadType;
@property (nonatomic, retain) G6PayVideoOffer *offerCurrentlyDownloading;
@property (nonatomic, retain) NSString *g6PayAppID;
@property (nonatomic, assign) BOOL statusBarWasHidden;
@property (nonatomic, assign) UIInterfaceOrientation videoOrientation;

-(id)initWithAppID:(NSString *)g6AppID prestitialSpaceID:(NSString *)spaceID delegate:(id<G6PayAdManagerDelegate>)theDelegate;
+(G6PayAdManager *)manager;
+(BOOL)playingVideoAd;
+(void)setPlayingVideoAd:(BOOL)playing;

+(NSString *)getVideoCacheDirectory;
-(void)createVideoCacheDicrectory;
-(NSURL *)getVideoOffersURL;

-(void)playVideoAd;
-(void)reloadVideoOffers;
-(G6PayVideoOffer *)getCachedActiveVideoOffer;
-(void)userCompletedVideoOffer:(G6PayVideoOffer *)offer;
-(void)videoAdWasRemoved;

-(G6PayConnectionType)getConnectionTypeForConnectionInfo:(NSDictionary*)userInfo;
-(void)parseXMLData:(NSData *)xmlData;
-(void)beginVideoAdForOffer:(G6PayVideoOffer *)offer;

@end
