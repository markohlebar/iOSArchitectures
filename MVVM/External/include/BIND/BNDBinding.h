//
//  BNDBinding.h
//  BIND
//
//  Created by Marko Hlebar on 27/10/2014.
//  Copyright (c) 2014 Marko Hlebar. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BNDBinding : NSObject

/**
 *  A bound object.
 */
@property (nonatomic, readonly) id object;

/**
 *  An object's keyPath.
 */
@property (nonatomic, copy, readonly) NSString *keyPath;

/**
 *  Other bound object.
 */
@property (nonatomic, readonly) id otherObject;

/**
 *  An other bound object's keyPath.
 */
@property (nonatomic, copy, readonly) NSString *otherKeyPath;

/**
 *  Value transfromer for transforming values coming from object to another object.
 */
@property (nonatomic, strong) NSValueTransformer *valueTransformer;

@end
