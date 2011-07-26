//
//  ABURLConnection.h
//  YouTube
//
//  Created by RyanBertrand on 7/13/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface G6PayURLConnection : NSURLConnection {
	NSDictionary *userInfo;
}

@property (nonatomic, retain) NSDictionary *userInfo;

@end
