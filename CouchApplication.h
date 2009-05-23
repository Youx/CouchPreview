//
//  CouchApplication.h
//  CouchPreview
//
//  Created by Hugo Camboulive on 21/05/09.
//  Copyright 2009 Université du Maine - IUP MIME. All rights reserved.
//

#import "PVApplication.h"

@interface PVApplication (CouchPV)

- (void) applicationWillBecomeActive: (NSNotification *)aNotification;
- (void) applicationWillResignActive: (NSNotification *)aNotification;

@end
