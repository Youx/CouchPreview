//
//  CouchPreview.m
//  CouchPreview
//
//  Created by Hugo Camboulive on 21/05/09.
//  Copyright 2009 Hugo Camboulive. All rights reserved.
//

#import "CouchPreview.h"
#import "RemoteControlWrapper/RemoteControlContainer.h"
#import "RemoteControlWrapper/AppleRemote.h"
#import "RemoteControlWrapper/KeyspanFrontRowControl.h"
#import "CouchApplication.h"
#import "JRSwizzle.h"

/* Dumped headers */
#import "PVImageWindowController.h"
#import "IKSlideshow.h"
#import "IKSlideshowController.h"


@implementation CouchPreview

+ (void) load
{
	CouchPreview *plugin = [CouchPreview sharedInstance];
	/* Handle remotes (Apple + remote for older macs) */
	plugin->cont = [[RemoteControlContainer alloc] initWithDelegate: plugin];
	[plugin->cont instantiateAndAddRemoteControlDeviceWithClass: [AppleRemote class]];
	[plugin->cont instantiateAndAddRemoteControlDeviceWithClass: [KeyspanFrontRowControl class]];
	[plugin->cont startListening: self];
	
	/* reset the delegate so that it get the methods we added */
	PVApplication *app = [NSApp delegate];
	[NSApp setDelegate: nil];
	[NSApp setDelegate: app];
}

+ (CouchPreview *) sharedInstance
{
	static CouchPreview* plugin = nil;

        if (plugin == nil)
                plugin = [[CouchPreview alloc] init];

        return plugin;
}

/**
 * This function handles whatever happens when a key on the remote is pressed
 * or released. Depending on the context, we update the slideshow or the normal view
 */
- (void) sendRemoteButtonEvent: (RemoteControlEventIdentifier)event pressedDown: (BOOL) pressedDown remoteControl: (RemoteControl *)remoteControl
{
	NSWindow *w = [NSApp mainWindow];
	if (pressedDown == NO)
		return;
	if (w == nil)
		return;
	/* We are in normal mode */
	if ([w isKindOfClass: NSClassFromString(@"PVWindow")]) {
		switch(event) {
			case kRemoteButtonRight:
				[[w windowController] doGoToNextPage:nil];
				break;
			case kRemoteButtonLeft:
				[[w windowController] doGoToPreviousPage:nil];
				break;
			case kRemoteButtonMenu:
				[[w windowController] slideshow: nil];
				break;
			case kRemoteButtonLeft_Hold:
				[[w windowController] doGoToFirstPage:nil];
				break;
			case kRemoteButtonRight_Hold:
				[[w windowController] doGoToLastPage:nil];
				break;
		}
	}

	/* We are in a slideshow. We use IKSlideshow private classes to control this
	 * (had to run class-dump on the ImageKit library */
	if ([w isKindOfClass: NSClassFromString(@"IKSlideshowWindow")]) {
		IKSlideshow *sld = [IKSlideshow sharedSlideshow];
		IKSlideshowController *ctl = [sld controller];

		switch(event) {
			case kRemoteButtonMenu:
				[sld stopSlideshow: nil];
				break;
			case kRemoteButtonRight:
				[ctl slideshowNext: nil];
				break;
			case kRemoteButtonLeft:
				[ctl slideshowPrev: nil];
				break;
			case kRemoteButtonPlay:
				[ctl slideshowPlay: nil];
				break;
			case kRemoteButtonRight_Hold:
				while([ctl canGoNext])
					[ctl gotoNextItem: nil];
				break;
			case kRemoteButtonLeft_Hold:
				while([ctl canGoBack])
					[ctl gotoPreviousItem:nil];
				break;
		}
	}
}
@end
