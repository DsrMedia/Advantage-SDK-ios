//
//  AVPlugin.h
//  Advantage
//
//  Created by Daniel Witurna on 11.07.13.
//  Copyright (c) 2013 Digitalsunray Media GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

@class AVWebView, Helper, AVFunctions;

@interface AVPlugin : NSObject{
    //Contains mapping from command-name to method name inside functions object.
    //e. g. command adopen --> openAd
    NSDictionary *_functionsMapping;
}

/// The functions object for forwarding invoked commands.
@property (nonatomic, strong, nonnull) AVFunctions *functions;

/// The string object of the separator for parsing the url for key and values. Set from core after retrieving a valid license.
@property (nonatomic, copy, nonnull) NSString *adServerSeparator;

/// Stores the pluginId set for a plugin. Can be nil.
@property (nonatomic, copy, readonly, nonnull) NSString *pluginId;

/// Stores the Ad server URL set for a plugin. only available for external plugin.
@property (nonatomic, copy, readonly, nonnull) NSString *adServerURL;

/// Stores the JSBridge set for a plugin. Can be nil.
@property (nonatomic, copy, readonly, nonnull) NSString *JSBridge;

/// Stores the Javascriptobject name for this plugin.
@property (nonatomic, copy, readonly, nonnull) NSString *recognitionString;

/// Stores the resource name of the js, if used. Returns for instance @"advantage" or @"mraid".
@property (nonatomic, copy, readonly, nonnull) NSString *jsResourceFilename;

@property (nonatomic, copy, readonly, nonnull) NSString *jsModifiedResource;

@property (nonatomic, copy, readonly, nonnull) NSString *jsRawResource;

/// Commands are send via this method to the plugin if appropriate. Returns TRUE, if command can be handled.
- (BOOL)invokeCommand:(nonnull WKScriptMessage *)completeCommand;

/// Legacy Commands (old js bridge, especially needed for mraid) are send via this method to the plugin if appropriate. Returns TRUE, if command can be handled.
- (BOOL)invokeLegacyCommand:(nonnull NSURLRequest *)completeCommand;


@end
