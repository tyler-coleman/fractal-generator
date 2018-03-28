//
//  RGB.h
//  Fractal
//
//  Created by Tyler Coleman on 3/19/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#ifndef RGB_h
#define RGB_h

using namespace std;

struct RGB {
    double r, g, b;
    RGB(double r, double g, double b);
};

RGB operator-(const RGB &first, const RGB &second);

#endif /* RGB_h */
