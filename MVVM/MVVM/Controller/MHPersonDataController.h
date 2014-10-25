//
//  MHTableDataController.h
//  MVVM
//
//  Created by Marko Hlebar on 25/10/2014.
//  Copyright (c) 2014 Marko Hlebar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MHDataController.h"

@class MHPersonFetcher;
@interface MHPersonDataController : NSObject <MHTableViewDataController>
@property (nonatomic, strong) MHPersonFetcher *dataFetcher;
@end
