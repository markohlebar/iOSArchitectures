//
//  MHNameViewModel.h
//  MVVM
//
//  Created by Marko Hlebar on 25/10/2014.
//  Copyright (c) 2014 Marko Hlebar. All rights reserved.
//

#ifndef MVVM_MHNameViewModel_h
#define MVVM_MHNameViewModel_h

#import "MHViewModel.h"

@protocol MHNameViewModel <MHTableViewModel>
- (NSString *)name;
@end

#endif
