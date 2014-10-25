//
//  MHColorTableCell.h
//  MVVM
//
//  Created by Marko Hlebar on 25/10/2014.
//  Copyright (c) 2014 Marko Hlebar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MHCell.h"

@protocol MHColorViewModel;
@interface MHColorTableCell : UITableViewCell <MHView>
- (void)updateWithViewModel:(id <MHColorViewModel> )viewModel;

@end