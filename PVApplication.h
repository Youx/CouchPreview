/*
 *  PVApplication.h
 *  CouchPreview
 *
 *  Created by Hugo Camboulive on 21/05/09.
 *  Copyright 2009 Université du Maine - IUP MIME. All rights reserved.
 *
 */

@class PVGrabbingFeedback;
@class PVGrabbingCoordView;
@class PVDocumentController;
@class PVGrabbingPie;

#import <Cocoa/Cocoa.h>

@interface PVApplication : NSApplication
{
	PVGrabbingFeedback *_feedbackWindow;
	PVGrabbingCoordView *_feedbackInfoView;
	PVGrabbingPie *_feedbackPie;
	PVGrabbingFeedback *_coordWindow;
	PVGrabbingCoordView *_coordView;
	unsigned int _outlineWindow;
	unsigned int _selectionWindow;
	unsigned int _lastWindow;
	NSString *_tempFolderPath;
	PVDocumentController *_documentController;
	NSBitmapImageRep *_lastGrabbedImageRep;
	float _coordWindowWidth;
	int _selectionMode;
	NSTimer *_stopwatchTimer;
	int _tickCount;
	struct _NSSize _screenDPI;
	NSMenuItem *_bookmarkMenu;
}

- (id)init;
- (void)awakeFromNib;
- (void)dealloc;
- (void)applicationDidFinishLaunching:(id)fp8;
- (void)didChangeScreenParametersNotification:(id)fp8;
- (void)applicationWillFinishLaunching:(id)fp8;
- (void)orderFrontColorPanel:(id)fp8;
- (void)orderFrontStandardAboutPanel:(id)fp8;
- (void)applicationWillTerminate:(id)fp8;
- (void)repopulateBookmarksMenu:(id)fp8;
- (void)activateBookmark:(id)fp8;
- (void)showBookmarks:(id)fp8;
- (void)deleteItem:(id)fp8;
- (void)doPrint:(id)fp8;
- (void)application:(id)fp8 openFiles:(id)fp12;
- (void)openPreferencePanel:(id)fp8;
- (BOOL)applicationShouldOpenUntitledFile:(id)fp8;
- (void)sendEvent:(id)fp8;
- (BOOL)validateMenuItem:(id)fp8;
- (id)tempFileFolderPath;
- (id)tempFileName:(id)fp8 untitledString:(id)fp12;
- (id)tempFileName:(id)fp8;
- (struct _NSPoint)annotationWindowOrigin:(id)fp8;
- (void)initiallyPositionWindowOrigin:(id)fp8;
- (void)newFromThisPasteboard:(id)fp8;
- (void)newFromClipboard:(id)fp8;
- (void)importImage:(id)fp8;
- (void)application:(id)fp8 runTest:(unsigned int)fp12 duration:(double)fp16;
- (id)documentController;

@end
