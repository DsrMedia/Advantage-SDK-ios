//
//  DataProtecionRights.h
//  Advantage
//
//  Created by Renato Neves Ribeiro on 20.07.20.
//  Copyright © 2020 Digitalsunray Media GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, DataProtectionType) {
    GDPR,
    IPL,
};

@interface DataProtecionRights : NSObject

@property (nonatomic, assign) DataProtectionType dprType;

@end
