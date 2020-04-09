//
//  ADvantage.h
//  Advantage
//
//  Created by Daniel Witurna on 28.05.13.
//  Copyright (c) 2013 Digitalsunray Media GmbH. All rights reserved.

#import "AdvantageDelegate.h"
#import "Permission.h"

@class AVPlugin;

typedef enum ADvantageLayoutType : NSUInteger {
    kADResponsiveLayout,
    kADDefaultLayout __deprecated_msg("Please use Responsive Layout: kADResponsiveLayout. Default Layout (kADDefaultLayout) will be removed in the future versions of ADvantage."),
} ADvantageLayoutType;

@interface ADvantage : NSObject

@property (nonatomic, strong, nonnull) UIView *view;
@property (nonatomic, weak, nullable) id<AdvantageDelegate> delegate;


@property (nonatomic, strong, nonnull) NSURL *offlineURL;
@property (nonatomic, copy, nonnull) NSString *siteId;
@property (nonatomic, copy, nonnull) NSString *position;
@property (nonatomic, copy, nonnull) NSString *loadingPicture;

@property (nonatomic, assign) ADvantageLayoutType layoutType;
@property (nonatomic, assign) BOOL showInterstitialAfterLoaded __deprecated_msg("The interstitial flow has been changed. A new method called 'showInterstitial' has been implemented for manually displaying the interstitial once it's loaded. Call it in the didLoad delegate of an interstitial ADvantage object. For more details and an example please refer to the documentation.");
@property (nonatomic, assign) BOOL transparentInterstitial;
@property (nonatomic, assign) BOOL scrollableBannersEnabled; // modal-views are always scrollable
@property (nonatomic, assign) BOOL isLoaded; // convenience property that goes along with the didLoad delegate
@property (nonatomic, strong, readonly, nonnull) Permission *permissions;
@property (nonatomic, strong, nullable) NSDictionary *fallBackAttributes;

//Banner

/*!
 *     Initializing an ADvantage object for banner
 *     \param licenseKey This is a valid key which is unique for each application and platform issued by ADvantage sales team.
 *  \param SSLEnabled This bool controls whether or not an SSL/HTTPS connection should be used. Set to YES in order to enable SSL. Using the init method without the SSLEnabled option, disables SSL by default (SSLEnabled:NO).
 *     \return ADvantage Banner instance
 */
- (nonnull id)initBannerWithLicenseKey:(nonnull NSString *)licenseKey SSLEnabled:(BOOL)SSLEnabled;
- (nonnull id)initBannerWithLicenseKey:(nonnull NSString *)licenseKey;

/*!
 *     Initializing an ADvantage object for banner with extra Plugin functionality
 *     \param licenseKey This is a valid key which is unique for each application and platform issued by ADvantage sales team.
 *  \param SSLEnabled This bool controls whether or not an SSL/HTTPS connection should be used. Set to YES in order to enable SSL. Using the init method without the SSLEnabled option, disables SSL by default (SSLEnabled:NO).
 *     \param plugin valid plugin instance with proper plugin properties
 *     \return ADvantage Banner instance
 */
- (nonnull id)initBannerWithLicenseKey:(nonnull NSString *)licenseKey SSLEnabled:(BOOL)SSLEnabled registerPlugin:(nonnull AVPlugin *)plugin;
- (nonnull id)initBannerWithLicenseKey:(nonnull NSString *)licenseKey registerPlugin:(nonnull AVPlugin *)plugin;

/*!
 *     Initializing an ADvantage object for banner
 *     \param licenseKey This is a valid key which is unique for each application and platform issued by ADvantage sales team.
 *  \param SSLEnabled This bool controls whether or not an SSL/HTTPS connection should be used. Set to YES in order to enable SSL. Using the init method without the SSLEnabled option, disables SSL by default (SSLEnabled:NO).
 *     \param siteId  represents the current siteID.
 *     \param position is linked to the advertisement and allocates the corresponding space on the screen.
 *     \return ADvantage Banner instance
 */
- (nonnull id)initBannerWithLicenseKey:(nonnull NSString *)licenseKey SSLEnabled:(BOOL)SSLEnabled SiteId:(nonnull NSString *)siteId Position:(nullable NSString *)position;
- (nonnull id)initBannerWithLicenseKey:(nonnull NSString *)licenseKey SiteId:(nonnull NSString *)siteId Position:(nullable NSString *)position;


/**
 Initialization of the maxPublisherBannerSize instance used for passing the value for the publisher banner size

 @param param type of CGSize and used for holding width and height of maxPublisherBannerSize property
 */
- (void)setMaxDimensionForBanner:(CGSize)param;

//Preload

/*!
 * 	Initializing an ADvantage object for Preload
 * 	\param licenseKey This is a valid key which is unique for each application and platform issued by ADvantage sales team.
 *  \param SSLEnabled This bool controls whether or not an SSL/HTTPS connection should be used. Set to YES in order to enable SSL. Using the init method without the SSLEnabled option, disables SSL by default (SSLEnabled:NO).
 * 	\return ADvantage Preload instance
 */
- (nonnull id)initPreloadWithLicenseKey:(nonnull NSString *)licenseKey SSLEnabled:(BOOL)SSLEnabled;
- (nonnull id)initPreloadWithLicenseKey:(nonnull NSString *)licenseKey;

/*!
 * 	Initializing an ADvantage object for Preload with extra Plugin functionality
 * 	\param licenseKey This is a valid key which is unique for each application and platform issued by ADvantage sales team.
 *  \param SSLEnabled This bool controls whether or not an SSL/HTTPS connection should be used. Set to YES in order to enable SSL. Using the init method without the SSLEnabled option, disables SSL by default (SSLEnabled:NO).
 * 	\param plugin valid plugin instance with proper plugin properties
 * 	\return ADvantage Preload instance
 */
- (nonnull id)initPreloadWithLicenseKey:(nonnull NSString *)licenseKey SSLEnabled:(BOOL)SSLEnabled registerPlugin:(nonnull AVPlugin *)plugin;
- (nonnull id)initPreloadWithLicenseKey:(nonnull NSString *)licenseKey registerPlugin:(nonnull AVPlugin *)plugin;

/*!
 * 	Initializing an ADvantage object for Preload
 * 	\param licenseKey This is a valid key which is unique for each application and platform issued by ADvantage sales team.
 *  \param SSLEnabled This bool controls whether or not an SSL/HTTPS connection should be used. Set to YES in order to enable SSL. Using the init method without the SSLEnabled option, disables SSL by default (SSLEnabled:NO).
 * 	\param siteId  represents the current siteID.
 * 	\param position is linked to the advertisement and allocates the corresponding space on the screen.
 * 	\return ADvantage Preload instance
 */
- (nonnull id)initPreloadWithLicenseKey:(nonnull NSString *)licenseKey SSLEnabled:(BOOL)SSLEnabled SiteId:(nonnull NSString *)siteId Position:(nonnull NSString *)position;
- (nonnull id)initPreloadWithLicenseKey:(nonnull NSString *)licenseKey SiteId:(nonnull NSString *)siteId Position:(nonnull NSString *)position;

/*!
 * 	Sending Request to ad server and load the ad.
 */
- (void)requestAd;

/*!
 * 	Sending Request to ad server and load the ad with a target.
 */
- (void)requestAdWithTarget:(nonnull NSString *)target;

/*!
 * 	Show interstitial after it has been loaded.
 */
- (void)showInterstitial;

/*!
 * 	Loading OfflineURL in a webview without any ADvantage functionality
 */
- (void)requestOfflineAd;

// Plugin

/*!
 * 	Register a plugin to ADvantage instance to have access to extra functionality provided by plugin.
 */
- (void)registerPlugin:(nonnull AVPlugin *)plugin;

/*!
 * add an object to be given to your ad provider, you MUST NOT encode the value as urlencoded, this is done by ADvantage view
 * \param paramName name of the parameter
 * \param paramValue value of the paramter
 */
- (void)addParameter:(nonnull NSString *)paramName withValue:(nonnull NSString *)paramValue;

/*!
 * Removes entry for given parameter name.
 * \param paramName name of the parameter
 */
-(void)removeParameter:(nonnull NSString *)paramName;

/*!
 * Removes all parameter entries.
 */
-(void)removeAllParameters;

/*!
 * Register custom protocols.
 */
-(void)registerCustomUrlSchemes:(nonnull NSArray <NSString*> *)protocols;

/*!
 * 	Adds the advantage instance to the key window to work around a limitation of iOS with the WKWebView (that happens in combination with the UITableView and similar use cases). Using this method is not mandatory, however once called, you have to make sure to call removeFromKeyWindow once your ad is finished loading and you're about to add it to another view such as a table view cell. This method will set the ad view hidden and add it to the application keyWindow. More information about this optional workaround and the rare edge case it applies to can be found in the documentation
 */
- (void)addToKeyWindow;

/*!
 * 	Sets the advantage view to visible (hidden NO) and removes the advantage view from the key window. More information on this can be found in the documentation
 */
- (void)removeFromKeyWindow;

- (void)setCornerAdHorizontalMargin:(CGFloat)margin;
- (void)setCornerAdVerticalMargin:(CGFloat)margin;

/*!
 * Set debugging for logs.
 */
-(void)setDebuggingEnabled:(BOOL)isDebuggingEnabled;

/*
 *
 * DEPRECATED init methods
 * ParentViewController parameter has been removed
 * These methods are still functional, however will be removed in a future release. Please use the init methods above
 *
 */

//Banner

/*!
 * 	Initializing an ADvantage object for banner
 * 	\param licenseKey This is a valid key which is unique for each application and platform issued by ADvantage sales team.
 *  \param SSLEnabled This bool controls whether or not an SSL/HTTPS connection should be used. Set to YES in order to enable SSL. Using the init method without the SSLEnabled option, disables SSL by default (SSLEnabled:NO).
 * 	\param parent This should be a UIViewController use to show Modal views.
 * 	\return ADvantage Banner instance
 */
- (nonnull id)initBannerWithLicenseKey:(nonnull NSString *)licenseKey SSLEnabled:(BOOL)SSLEnabled ParentViewController:(nonnull UIViewController *)parent __deprecated_msg("Please use the new init methods without the ParentViewController parameter. The UIViewController for displaying modal views is determined automatically since v2.5.0");
- (nonnull id)initBannerWithLicenseKey:(nonnull NSString *)licenseKey ParentViewController:(nonnull UIViewController *)parent __deprecated_msg("Please use the new init methods without the ParentViewController parameter. The UIViewController for displaying modal views is determined automatically since v2.5.0");

/*!
 * 	Initializing an ADvantage object for banner with extra Plugin functionality
 * 	\param licenseKey This is a valid key which is unique for each application and platform issued by ADvantage sales team.
 * 	\param parent This should be a UIViewController use to show Modal views.
 * 	\param plugin valid plugin instance with proper plugin properties
 * 	\return ADvantage Banner instance
 */
- (nonnull id)initBannerWithLicenseKey:(nonnull NSString *)licenseKey ParentViewController:(nonnull UIViewController *)parent registerPlugin:(nonnull AVPlugin *)plugin __deprecated_msg("Please use the new init methods without the ParentViewController parameter. The UIViewController for displaying modal views is determined automatically since v2.5.0");
- (nonnull id)initBannerWithLicenseKey:(nonnull NSString *)licenseKey SSLEnabled:(BOOL)SSLEnabled ParentViewController:(nonnull UIViewController *)parent registerPlugin:(nonnull AVPlugin *)plugin __deprecated_msg("Please use the new init methods without the ParentViewController parameter. The UIViewController for displaying modal views is determined automatically since v2.5.0");

/*!
 * 	Initializing an ADvantage object for banner
 * 	\param licenseKey This is a valid key which is unique for each application and platform issued by ADvantage sales team.
 *  \param SSLEnabled This bool controls whether or not an SSL/HTTPS connection should be used. Set to YES in order to enable SSL. Using the init method without the SSLEnabled option, disables SSL by default (SSLEnabled:NO).
 * 	\param parent This should be a UIViewController use to show Modal views.
 * 	\param siteId  represents the current siteID.
 * 	\param position is linked to the advertisement and allocates the corresponding space on the screen.
 * 	\return ADvantage Banner instance
 */
- (nonnull id)initBannerWithLicenseKey:(nonnull NSString *)licenseKey SSLEnabled:(BOOL)SSLEnabled ParentViewController:(nonnull UIViewController *)parent SiteId:(nonnull NSString *)siteId Position:(nonnull NSString *)position __deprecated_msg("Please use the new init methods without the ParentViewController parameter. The UIViewController for displaying modal views is determined automatically since v2.5.0");
- (nonnull id)initBannerWithLicenseKey:(nonnull NSString *)licenseKey ParentViewController:(nonnull UIViewController *)parent SiteId:(nonnull NSString *)siteId Position:(nonnull NSString *)position __deprecated_msg("Please use the new init methods without the ParentViewController parameter. The UIViewController for displaying modal views is determined automatically since v2.5.0");

//Preload

/*!
 * 	Initializing an ADvantage object for Preload
 * 	\param licenseKey This is a valid key which is unique for each application and platform issued by ADvantage sales team.
 *  \param SSLEnabled This bool controls whether or not an SSL/HTTPS connection should be used. Set to YES in order to enable SSL. Using the init method without the SSLEnabled option, disables SSL by default (SSLEnabled:NO).
 * 	\param parent This should be a UIViewController use to show Modal views.
 * 	\return ADvantage Preload instance
 */
- (nonnull id)initPreloadWithLicenseKey:(nonnull NSString *)licenseKey SSLEnabled:(BOOL)SSLEnabled ParentViewController:(nonnull UIViewController *)parent __deprecated_msg("Please use the new init methods without the ParentViewController parameter. The UIViewController for displaying modal views is determined automatically since v2.5.0");
- (nonnull id)initPreloadWithLicenseKey:(nonnull NSString *)licenseKey ParentViewController:(nonnull UIViewController *)parent __deprecated_msg("Please use the new init methods without the ParentViewController parameter. The UIViewController for displaying modal views is determined automatically since v2.5.0");

/*!
 * 	Initializing an ADvantage object for Preload with extra Plugin functionality
 * 	\param licenseKey This is a valid key which is unique for each application and platform issued by ADvantage sales team.
 *  \param SSLEnabled This bool controls whether or not an SSL/HTTPS connection should be used. Set to YES in order to enable SSL. Using the init method without the SSLEnabled option, disables SSL by default (SSLEnabled:NO).
 * 	\param parent This should be a UIViewController use to show Modal views.
 * 	\param plugin valid plugin instance with proper plugin properties
 * 	\return ADvantage Preload instance
 */
- (nonnull id)initPreloadWithLicenseKey:(nonnull NSString *)licenseKey SSLEnabled:(BOOL)SSLEnabled ParentViewController:(nonnull UIViewController *)parent registerPlugin:(nonnull AVPlugin *)plugin __deprecated_msg("Please use the new init methods without the ParentViewController parameter. The UIViewController for displaying modal views is determined automatically since v2.5.0");
- (nonnull id)initPreloadWithLicenseKey:(nonnull NSString *)licenseKey ParentViewController:(nonnull UIViewController *)parent registerPlugin:(nonnull AVPlugin *)plugin __deprecated_msg("Please use the new init methods without the ParentViewController parameter. The UIViewController for displaying modal views is determined automatically since v2.5.0");

/*!
 * 	Initializing an ADvantage object for Preload
 * 	\param licenseKey This is a valid key which is unique for each application and platform issued by ADvantage sales team.
 *  \param SSLEnabled This bool controls whether or not an SSL/HTTPS connection should be used. Set to YES in order to enable SSL. Using the init method without the SSLEnabled option, disables SSL by default (SSLEnabled:NO).
 * 	\param parent This should be a UIViewController use to show Modal views.
 * 	\param siteId  represents the current siteID.
 * 	\param position is linked to the advertisement and allocates the corresponding space on the screen.
 * 	\return ADvantage Preload instance
 */
- (nonnull id)initPreloadWithLicenseKey:(nonnull NSString *)licenseKey SSLEnabled:(BOOL)SSLEnabled ParentViewController:(nonnull UIViewController *)parent SiteId:(nonnull NSString *)siteId Position:(nonnull NSString *)position __deprecated_msg("Please use the new init methods without the ParentViewController parameter. The UIViewController for displaying modal views is determined automatically since v2.5.0");
- (nonnull id)initPreloadWithLicenseKey:(nonnull NSString *)licenseKey ParentViewController:(nonnull UIViewController *)parent SiteId:(nonnull NSString *)siteId Position:(nonnull NSString *)position __deprecated_msg("Please use the new init methods without the ParentViewController parameter. The UIViewController for displaying modal views is determined automatically since v2.5.0");
/**
 * Dispose the current instance of advantage and destroys the internal state of this instance.
 * Destroys the internal state of current ADvantage instance and remove all its childs(views).
 * Further, it removes the current instance from its parent and stop all listeners, timer(s) and observer(s).
 */
- (void)dispose;

@end
