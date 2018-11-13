//
//  AdvantageDelegate.h
//  Advantage
//
//  Created by Daniel Witurna on 11.07.13.
//  Copyright (c) 2013 Digitalsunray Media GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ADvantage;

typedef NS_ENUM(NSUInteger, AVLoadedState) {
    AVLoadedWithAd,
    AVLoadedWithoutAd
};

/*
 * Delegate for the ADvantage object. SDK implementer has to
 * use this protocol.
 */
@protocol AdvantageDelegate <NSObject>

@optional

/*!
 * 	Called when the Advantage object has finished loading an ad.
 * 	\param advantage ADvantage object that finished loading.
 * 	\param state If there is a ad campaign for the setup advantage object, the state will be AVLoadedWithAd, otherwise AVLoadedWithoutAd.
 */
- (void)advantage:(nonnull ADvantage *)advantage didLoad:(AVLoadedState)state;

/*!
 * 	Called when the ADvantage object was not able to load an ad.
 * 	\param advantage ADvantage object that failed loading.
 * 	\param error Error description.
 */
- (void)advantage:(nonnull ADvantage *)advantage didFailWithError:(nullable NSString *)error;

/*!
 * 	Called when the ADvantage objects did expand.
 * 	\param advantage ADvantage object that expaned.
 * 	\param rect The rect the object expanded to.
 */
- (void)advantage:(nonnull ADvantage *)advantage didExpandTo:(CGRect)rect;

/*!
 * 	Called when the ADvantage objects did resize.
 * 	\param advantage ADvantage object that resized.
 * 	\param rect The rect the object resized to.
 */
- (void)advantage:(nonnull ADvantage *)advantage didResizeTo:(CGRect)rect;

/*!
 * 	Called when the ADvantage objects layout did Moved and Resized.
 * 	\param advantage ADvantage object that Moved.
 * 	\param rect The rect the object resized to.
 */
- (void)advantage:(nonnull ADvantage *)advantage didUpdateLayoutTo:(CGRect)rect;

/*!
 * 	Called when the ADvantage objects did close.
 * 	\param advantage ADvantage object that closed.
 */
- (void)advantageDidClose:(nonnull ADvantage *)advantage;

/*!
 * 	Called when there is a notification sent from the ad creative to the SDK Developer.
 * 	\param advantage ADvantage object that notifies.
 * 	\param message Notification sent from creative.
 */
- (void)advantage:(nonnull ADvantage *)advantage notifyWithMessage:(nullable NSString *)message;


/*!
 * 	Called when there is a notification sent from the ad creative to the SDK Developer.
 * 	\param advantage ADvantage object that notifies.
 * 	\param dic Notification sent from creative.
 */
- (void)advantage:(nonnull ADvantage *)advantage notifyWithDictionary:(nonnull NSDictionary *)dic;

/*!
 * 	Called when a url with a previously defined custom protocol is called from the ad creative. Supports direct href calls, mraid open and advantage adopen
 * 	\param advantage ADvantage object that notifies.
 * 	\param url that was called.
 */
- (void)advantage:(nonnull ADvantage *)advantage didCallUrlWithCustomUrlScheme:(nonnull NSURL *)url;

/*!
 * 	Called when a social ad sets a target.
 * 	\param advantage ADvantage object that notifies.
 * 	\param target that was set.
 */
- (void)advantage:(nonnull ADvantage *)advantage didReceiveSocialAd:(nonnull NSString *)target;

/*!
 * 	The top inset relative to the understitial's container (usually a scrollview or tableview) for the understitial ad.
 *  If provided, the insets calculation procedure will be bypassed and the
 *  provided value will be used instead.
 */
- (CGFloat)topInsetForUnderstitial;

@end
