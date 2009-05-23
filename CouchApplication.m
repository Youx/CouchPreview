//
//  CouchApplication.m
//  CouchPreview
//
//  Created by Hugo Camboulive on 21/05/09.
//  Copyright 2009 Université du Maine - IUP MIME. All rights reserved.
//

#import "CouchApplication.h"
#import "CouchPreview.h"


@implementation PVApplication (CouchPV)

- (void) applicationWillBecomeActive: (NSNotification *)aNotification
{
	[[CouchPreview sharedInstance]->cont startListening: [CouchPreview sharedInstance]];
}

- (void) applicationWillResignActive: (NSNotification *)aNotification
{
	[[CouchPreview sharedInstance]->cont stopListening: [CouchPreview sharedInstance]];
}

@end
