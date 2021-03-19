//  Copyright 2016 LinkedIn Corporation
//  Licensed under the BSD 2-Clause License (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at https://opensource.org/licenses/BSD-2-Clause
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OF ANY KIND, either express or implied.  See the License for the specific language governing permissions and limitations under the License.

#import <Foundation/Foundation.h>
#import "bp/src/BPXCTestFile.h"
#import "bp/src/BPConfiguration.h"

@interface BPTask : NSObject

@property (nonatomic, assign) NSUInteger laneID;
@property (nonatomic, strong) NSTask *task; //TODO: SSSYYY Maybe weak so that it could be nil after terminated
@property (nonatomic, assign) NSUInteger taskNumber;

/*!
 * @discussion get a BPTask to execute `bp`.
 * @param laneID the Lane ID that keeps the same for `bp` tasks.
 * @return return the BPTask.
 */
+ (instancetype)BPTaskWithLaneID:(NSUInteger)laneID;

/*!
 * @discussion Launch a NSTask to create a new Simulator wrapped in a `bp` process. It will run the specified bundle and execute the block once it finishes.
 * @param bundle The test bundle to execute.
 * @param config The BPConfiguration of the BPRunner.
 * @param number The simulator number (will be printed in logs). *
 * @param block A completion block to execute when the NSTask has finished.
 *
 */
- (void)launchTaskWithBundle:(BPXCTestFile *)bundle
                   andConfig:(BPConfiguration *)config
                   andNumber:(NSUInteger)number
                   andDevice:(NSString *)deviceID
          andCompletionBlock:(void (^)(BPTask * ))block;

// TODO: SSSYYY
- (int)processIdentifier;
- (int)terminationStatus;

@end
