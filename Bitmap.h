//
//  Bitmap.h
//  Fractal
//
//  Created by Tyler Coleman on 3/5/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#ifndef Bitmap_h
#define Bitmap_h

#include <string>
#include <cstdint>
#include <memory>

using namespace std;

class Bitmap {
private:
    int m_width{0};
    int m_height{0};
    unique_ptr<uint8_t[]> m_pPixels{nullptr}; // Declaring as unique pointer saves us from having to delete []
                                              // assigned memory later.
    
public:
    Bitmap(int width, int height);
    virtual ~Bitmap();
    
    bool write(string file_name);
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
};

#endif /* Bitmap_h */

