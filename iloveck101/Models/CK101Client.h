//
//  CK101Client.h
//  iloveck101
//
//  Created by Chong Francis on 13年12月23日.
//  Copyright (c) 2013年 Ignition Soft. All rights reserved.
//

#import "AFHTTPSessionManager.h"

@interface CK101Client : AFHTTPSessionManager

+(instancetype)sharedClient;

@end
