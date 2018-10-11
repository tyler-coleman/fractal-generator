//
//  ZoomList.h
//  Fractal
//
//  Created by Tyler Coleman on 3/16/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#ifndef ZoomList_h
#define ZoomList_h

#include <vector>
#include <utility>
#include "Zoom.h"

using namespace std;

class ZoomList {
private:
    double m_xCenter{0};
    double m_yCenter{0};
    double m_scale{1.0};
    int m_width{0};
    int m_height{0};
    vector<Zoom> zooms;
public:
    ZoomList(int width, int height);
    void add(const Zoom &zoom);
    void remove();
    pair<double, double> doZoom(int x, int y); // Takes pixel argument and returns some information about the new frame.
};

#endif /* ZoomList_h */
