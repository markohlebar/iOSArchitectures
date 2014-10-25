//
//  MHTableDataController.m
//  MVVM
//
//  Created by Marko Hlebar on 25/10/2014.
//  Copyright (c) 2014 Marko Hlebar. All rights reserved.
//

#import "MHPersonDataController.h"
#import "MHPersonFetcher.h"
#import "MHNameViewModel.h"
#import "MHColorViewModel.h"
#import "MHPerson.h"
#import "UIColor+Hex.h"

@interface MHPersonNameViewModel : NSObject <MHNameViewModel>
@property (nonatomic, strong, readonly) MHPerson *person;
@end

@implementation MHPersonNameViewModel

+ (instancetype)viewModelWithModel:(MHPerson *)person {
    return [[self alloc] initWithModel:person];
}

- (instancetype)initWithModel:(MHPerson *)person {
    self = [super init];
    if (self) {
        _person = person;
    }
    return self;
}

- (NSString *)name {
    return self.person.fullName;
}

- (NSString *)identifier {
    static NSString *_nameIdentifier = @"MHNameTableCell";
    return _nameIdentifier;
}

- (CGFloat)cellHeight {
    return 44;
}

@end

@interface MHPersonColorViewModel : NSObject <MHColorViewModel>
@property (nonatomic, strong, readonly) MHPerson *person;
@end

@implementation MHPersonColorViewModel

+ (instancetype)viewModelWithModel:(MHPerson *)person {
    return [[self alloc] initWithModel:person];
}

- (instancetype)initWithModel:(MHPerson *)person {
    self = [super init];
    if (self) {
        _person = person;
    }
    return self;
}

- (UIColor *)color {
    return [UIColor colorFromHexString:self.person.hexColorCode];
}

- (NSString *)identifier {
    static NSString *_colorIdentifier = @"MHColorTableCell";
    return _colorIdentifier;
}

- (CGFloat)cellHeight {
    return 80;
}

@end

@implementation MHPersonDataController

- (instancetype)init {
    self = [super init];
    if (self) {
        _dataFetcher = [MHPersonFetcher new];
    }
    return self;
}

- (void)reloadData:(MHViewModelBlock)dataBlock {
    [self.dataFetcher fetchPersonae:^(NSArray *personae) {
        NSArray *viewModels = [self prepareViewModelForPersonae:personae];
        dataBlock(viewModels, nil);
    }];
}

- (NSArray *)prepareViewModelForPersonae:(NSArray *)personae {
    NSMutableArray *viewModels = [NSMutableArray new];
    for (MHPerson *person in personae) {
        Class viewModelClass = (person.ID.integerValue % 2 == 0) ?
        [MHPersonNameViewModel class] :
        [MHPersonColorViewModel class];
        
        id viewModel = [viewModelClass viewModelWithModel:person];
        [viewModels addObject:viewModel];
    }
    return viewModels.copy;
}

@end
