//
//  Bitmap.cpp
//  Fractal
//
//  Created by Tyler Coleman on 3/5/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <fstream>
#include <iostream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace std;

Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{}) {
    
}

Bitmap::~Bitmap() {}

bool Bitmap::write(string fileName) {
    
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;
    
    fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
    
    infoHeader.width = m_width;
    infoHeader.height = m_height;
    
    ofstream outf;
    outf.open(fileName, ios::out | ios::binary);
    
    if (!outf) {
        return false;
    }
    
    outf.write((char *)&fileHeader, sizeof(fileHeader));
    outf.write((char *)&infoHeader, sizeof(infoHeader));
    outf.write((char *)m_pPixels.get(), m_width * m_height * 3); // get() method of uniqueptr returns regular raw
                                                                 // pointer used by template.
    
    outf.close();
    
    // Check for error condition.
    if (!outf) {
        return false;
    }
    
    return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    
    uint8_t *pPixel = m_pPixels.get();
    pPixel += (3 * y)  * m_width + (3 * x); // Each pixel takes up 3 bytes in memory.
    
    // Colors are reveresed because bmp is a little-endian file format.
    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;
    
}
