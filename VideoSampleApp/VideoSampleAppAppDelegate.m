//
//  VideoSampleAppAppDelegate.m
//  VideoSampleApp
//
//  Created by Rangel Spasov on 7/25/11.
//  Copyright 2011 G6 Media Inc. All rights reserved.
//
#import "G6PayVideoAds.h"
#import "VideoSampleAppAppDelegate.h"

@implementation VideoSampleAppAppDelegate

@synthesize window = _window;
@synthesize navigationController = _navigationController;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{   
    //Init a G6PayAdManager object to gather video ads and display 
    
    videoAdManager = [[G6PayAdManager alloc] 
                      initWithAppID:@"appId"        
                      prestitialSpaceID:@"prestitialSpaceId" delegate:self];
    [videoAdManager playVideoAd];
    
    // Override point for customization after application launch.
    // Add the navigation controller's view to the window and display.
    self.window.rootViewController = self.navigationController;
    [self.window makeKeyAndVisible];
    
    
    return YES;
}

-(void)g6VideoAdsReadyInSpace:(NSString *)spaceID{
    [videoAdManager playVideoAd];
}
//Called when you call the playVideoAd method but the VideoAd has not finished preparing.
-(void)g6VideoAdsNotReadyInSpace:(NSString *)spaceID{
    NSLog(@"Ads not ready in spaceID: %@", spaceID);
}
//Called when G6Pay does not have any ads to fill your spaceID
-(void)g6VideoNoVideoFillInSpace:(NSString *)spaceID{
    NSLog(@"No videos in spaceID:%@", spaceID);
}
//Called when the VideoAd Player has given control back to your  application.
-(void)g6VideoAdDidEndTakeover{
    //Resume music, game, etc.
    NSLog(@"Ad ended.");
}
-(void)g6VideoAdIsAlreadyPlaying{
    //Called when you try to play another VideoAd when one is currently playing
    NSLog(@"Video Ad is Already Playing");

}


- (void)applicationWillResignActive:(UIApplication *)application
{
    /*
     Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
     Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
     */
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    /*
     Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
     If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
     */
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    /*
     Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
     */
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    /*
     Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
     */
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    /*
     Called when the application is about to terminate.
     Save data if appropriate.
     See also applicationDidEnterBackground:.
     */
}

- (void)dealloc
{
    [_window release];
    [_navigationController release];
    [super dealloc];
}

@end
