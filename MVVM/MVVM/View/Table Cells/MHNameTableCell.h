//
//  MHNameTableCell.h
//  MVVM
//
//  Created by Marko Hlebar on 25/10/2014.
//  Copyright (c) 2014 Marko Hlebar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MHView.h"

@protocol MHNameViewModel;
@interface MHNameTableCell : UITableViewCell <MHView>
- (void)updateWithViewModel:(id <MHNameViewModel> )viewModel;
@end
