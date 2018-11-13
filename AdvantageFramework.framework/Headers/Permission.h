//
//  Permission.h
//  Advantage
//
//  Created by Mohsen Fazeliniaki on 7/11/13.
//  Copyright (c) 2013 Digitalsunray Media GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Permission : NSObject

@property (nonatomic, assign, getter=isSmsAllowed)           BOOL smsAllowed;
@property (nonatomic, assign, getter=isTelAllowed)           BOOL telAllowed;
@property (nonatomic, assign, getter=isCalendarAllowed)      BOOL calendarAllowed;
@property (nonatomic, assign, getter=isStorePictureAllowed)  BOOL storePictureAllowed;
@property (nonatomic, assign, getter=isInlineVideoAllowed)   BOOL inlineVideoAllowed;
@property (nonatomic, assign, getter=isRotationAllowed)      BOOL rotationAllowed;
@property (nonatomic, assign, getter=isContactAllowed)       BOOL contactAllowed;
@property (nonatomic, assign)                                BOOL sensorsAllowed;
//sensitive
@property (nonatomic, assign, getter=isUserLocationAllowed)       BOOL userLocationAllowed;
@property (nonatomic, assign, getter=isBluetoothAllowed)          BOOL bluetoothAllowed;
//@property (nonatomic, assign, getter=isNFCAllowed)                BOOL nfcAllowed;
@property (nonatomic, assign, getter=isBatteryLevelAllowed)       BOOL batteryLevelAllowed;
@property (nonatomic, assign, getter=isLanguageFullCodeAllowed)   BOOL languageFullCodeAllowed;
@property (nonatomic, assign, getter=isLanguageShortCodeAllowed)  BOOL languageShortCodeAllowed;
@property (nonatomic, assign, getter=isDeviceCountryCodeAllowed)  BOOL deviceCountryCodeAllowed;


typedef NS_ENUM(NSUInteger, AVMRAIDSupports) {
    AVMRAIDSupportsSMS,
    AVMRAIDSupportsTel,
    AVMRAIDSupportsCalendar,
    AVMRAIDSupportsStorePicture,
    AVMRAIDSupportsInlineVideo,
    AVMRAIDSupportsLocation,
    AVMRAIDSupportsRotation,
    AVMRAIDSupportsCompass,
    AVMRAIDSupportsAccelerometer,
    AVMRAIDSupportsGyroscope,
    AVMRAIDSupportsContact,
    AVMRAIDSupportsProximity,
    AVMRAIDSupportsPedometer,
    AVMRAIDSupportsBarometer
};

/**
 Method that helps to convert enum values of AVMRAIDSupports to the string.

 @param value is a enum type of AVMRAIDSupports
 @return return NSString type.
 */
+ (nonnull NSString *)convertToString:(AVMRAIDSupports)value;

/**
 * To set up all permission means to set all targeting parameters to TRUE.
 */
- (void)setAllPermission;

/**
 Setting up sensitive targeting. It is possible to set up parameters bellow to be allowed or disabled to sending information about related sensor.

     - property userLocationAllowed;
     - property bluetoothAllowed;
     - property nfcAllowed;
     - property batteryLevelAllowed;
     - property languageFullCodeAllowed;
     - property languageShortCodeAllowed;
     - property deviceCountryCodeAllowed;

 @param isAllowed is boolean value which can be set to true or false.
 */
- (void)setSensitiveTargetingParametersAllowed:(BOOL)isAllowed;

@end
