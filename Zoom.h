//
//  Zoom.h
//  Fractal
//
//  Created by Tyler Coleman on 3/16/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#ifndef Zoom_h
#define Zoom_h

using namespace std;

struct Zoom {
    Zoom(int x, int y, double scale) : x(x), y(y), scale(scale) {};
    
    int x{0};
    int y{0};
    double scale{0.0};
};


#endif /* Zoom_h */
