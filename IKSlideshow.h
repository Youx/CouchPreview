/*
 *  IKSlideshow.h
 *  CouchPreview
 *
 */

@interface IKSlideshow (ImageKit)

+ (id)sharedSlideshow;
+ (BOOL)canExportToApplication:(id)fp8;
+ (void)exportSlideshowItem:(id)fp8 toApplication:(id)fp12;
+ (void)exportSlideshowItemToApplication:(id)fp8 application:(id)fp12;
- (id)init;
- (void)disposeData;
- (void)dealloc;
- (void)finalize;
- (id)controller;
- (void)runSlideshowWithDataSource:(id)fp8 inMode:(id)fp12 options:(id)fp16;
- (void)stopSlideshow:(id)fp8;
- (void)reloadData;
- (void)reloadSlideshowItemAtIndex:(unsigned int)fp8;
- (unsigned int)indexOfCurrentSlideshowItem;
- (double)autoPlayDelay;
- (void)setAutoPlayDelay:(double)fp8;

@end