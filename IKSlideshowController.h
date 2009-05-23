/*
 *  IKSlideshowController.h
 *  CouchPreview
 */
@class IKSlideshow;
@class IKSlideshowEngine;
@class IKSlideshowPanel;
@class IKSlideshowIndexHandler;

@interface IKSlideshowController : NSObject
{
	IKSlideshow *_slideshow;
	IKSlideshowEngine *_engine;
	IKSlideshowPanel *_panel;
	IKSlideshowIndexHandler *_indexHandler;
	id _dataSource;
	NSDictionary *_options;
	NSString *_slideshowMode;
	double _autoPlayDelay;
	BOOL _wrapsAround;
	BOOL _canGoBack;
	BOOL _canGoNext;
	BOOL _switchedToIndexMode;
	BOOL _switchedToToFullScreen;
	BOOL _exportToiPhoto;
	BOOL _itemSupportedByiPhoto;
	BOOL _autoPlay;
}

- (id)initWithSlideshow:(id)fp8 dataSource:(id)fp12 slideshowMode:(id)fp16 options:(id)fp20;
- (void)dealloc;
- (void)closeDown;
- (void)setWrapsAround:(BOOL)fp8;
- (void)setup;
- (void)run;
- (id)engine;
- (id)panel;
- (id)indexHandler;
- (void)setupPanel;
- (void)runAutoPlay:(id)fp8;
- (void)updateCanGoBackAndNext;
- (void)pause;
- (void)resume;
- (void)autoPlayNextItem:(id)fp8;
- (void)gotoNextItem:(id)fp8;
- (void)gotoPreviousItem:(id)fp8;
- (void)exitSlideshow:(id)fp8;
- (void)reloadData;
- (void)numberOfItemsChanged;
- (void)reloadSlideshowItemAtIndex:(unsigned int)fp8;
- (void)setupIndexHandler;
- (void)slideshowPrev:(id)fp8;
- (void)slideshowNext:(id)fp8;
- (void)slideshowPlay:(id)fp8;
- (void)slideshowPlayStopped:(id)fp8;
- (void)slideshowSwitchToSinglePage:(id)fp8;
- (void)slideshowSwitchToIndexMode:(id)fp8;
- (void)slideshowSwitchToFullScreen:(id)fp8;
- (void)slideshowSwitchToActualSize:(id)fp8;
- (void)slideshowExportToiPhoto:(id)fp8;
- (void)slideshowDontExportToiPhoto:(id)fp8;
- (void)slideshowClose:(id)fp8;
- (BOOL)autoPlay;
- (void)setAutoPlay:(BOOL)fp8;
- (BOOL)itemSupportedByiPhoto;
- (void)setItemSupportedByiPhoto:(BOOL)fp8;
- (BOOL)exportToiPhoto;
- (void)setExportToiPhoto:(BOOL)fp8;
- (BOOL)switchedToToFullScreen;
- (void)setSwitchedToToFullScreen:(BOOL)fp8;
- (BOOL)switchedToIndexMode;
- (void)setSwitchedToIndexMode:(BOOL)fp8;
- (BOOL)canGoNext;
- (void)setCanGoNext:(BOOL)fp8;
- (BOOL)canGoBack;
- (void)setCanGoBack:(BOOL)fp8;
- (BOOL)wrapsAround;
- (double)autoPlayDelay;
- (void)setAutoPlayDelay:(double)fp8;
- (id)slideshowMode;
- (void)setSlideshowMode:(id)fp8;
- (id)options;
- (void)setOptions:(id)fp8;
- (id)dataSource;
- (void)setDataSource:(id)fp8;

@end
