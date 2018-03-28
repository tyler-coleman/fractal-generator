//
//  RGB.cpp
//  Fractal
//
//  Created by Tyler Coleman on 3/19/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <stdio.h>
#include "RGB.h"

RGB::RGB(double r, double g, double b) : r(r), g(g), b(b) {
    
}

RGB operator-(const RGB &first, const RGB &second) {
    return RGB(first.r - second.r, first.g - second.g, first.b - second.b);
}
