//
//  GeneralDataProtecionRights.h
//  Advantage
//
//  Created by Renato Neves Ribeiro on 20.07.20.
//  Copyright © 2020 Digitalsunray Media GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DataProtecionRights.h"

@interface GeneralDataProtecionRights : DataProtecionRights

@property (nonatomic, assign) BOOL gdpr;
@property (nonatomic, assign) BOOL gdprPD;
@property (nonatomic, strong) NSString *gdprConsent;
@property (nonatomic, strong) NSString *addtlConsent;

-(instancetype)initWithParametersGDPR:(BOOL)gdpr gdprPD:(BOOL)gdprPD gdprConsent:(NSString *)consent andAddtlConsent:(NSString *)addtleConsent;

@end
