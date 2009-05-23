//
//  CouchPreview.h
//  CouchPreview
//
//  Created by Hugo Camboulive on 21/05/09.
//  Copyright 2009 Université du Maine - IUP MIME. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "RemoteControlWrapper/RemoteControlContainer.h"

@interface CouchPreview : NSObject {
	@public
	RemoteControlContainer *cont;
}

+ (void)load;
+ (CouchPreview *)sharedInstance;

@end
