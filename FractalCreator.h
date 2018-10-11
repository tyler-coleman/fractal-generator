//
//  FractalCreator.h
//  Fractal
//
//  Created by Tyler Coleman on 3/19/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#ifndef FractalCreator_h
#define FractalCreator_h

#include <string>
#include <vector>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"
#include "Screen.h"

using namespace std;

class FractalCreator {
private:
    Screen screen;
    int m_width, m_height, m_total{0};
    unique_ptr<int[]> m_histogram;
    unique_ptr<int[]> m_fractal;
    Bitmap m_bmp;
    ZoomList m_zoomList;
    
    vector<int> m_ranges;
    vector<RGB> m_colors;
    vector<int> m_rangeTotals;
    
    bool m_bGotFirstRange{false};
    
    void calculateIterations();
    void drawFractal();
    void writeBitmap(string fileName);
    void calculateTotalIterations();
    void calculateRangeTotals();
    int getRange(int iterations) const; // const because it doesn't modify any member variables.
    
public:
    FractalCreator(int width, int height);
    virtual ~FractalCreator();
    void addZoom(const Zoom &zoom);
    void addRange(double rangeEnd, const RGB &rgb);
    void run(string fileName);
};

#endif /* FractalCreator_h */
