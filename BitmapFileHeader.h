//
//  BitmapFileHeader.h
//  Fractal
//
//  Created by Tyler Coleman on 3/5/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#ifndef BitmapFileHeader_h
#define BitmapFileHeader_h

#include <cstdint>

using namespace std;

#pragma pack(push,2)

struct BitmapFileHeader {
    char header[2]{'B','M'}; // Can initialize like this only in C++11.
    int32_t fileSize; // Must be 4 bytes exactly (32 bits).
    int32_t reserved{0};
    int32_t dataOffset;
};

#pragma pack(pop)

#endif /* BitmapFileHeader_h */
