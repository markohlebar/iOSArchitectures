//
//  BNDTableViewCell.h
//  BIND
//
//  Created by Marko Hlebar on 27/10/2014.
//  Copyright (c) 2014 Marko Hlebar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BNDView.h"

/**
 *  BNDTableViewCell is an abstract cell that loads data binder 
 *  from a XIB and then refreshes the bindings when the 
 *  cell gets updated. 
 *  The user of this cell should call updateWithViewModel: 
 *  in UITableViewDelegate's tableView:cellForRowAtIndexPath: method
 *  so that the bindings get updated.
 */
@class BNDBinder;
@interface BNDTableViewCell : UITableViewCell <BNDView>
@property (nonatomic, strong) IBOutlet BNDBinder *dataBinder;
@end
