//
//  Mandelbrot.h
//  Fractal
//
//  Created by Tyler Coleman on 3/14/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#ifndef Mandelbrot_h
#define Mandelbrot_h

using namespace std;

class Mandelbrot {
public:
    static const int MAX_ITERATIONS = 1000;
    
    Mandelbrot();
    virtual ~Mandelbrot();
    
    static int getIterations(double x, double y);
};


#endif /* Mandelbrot_h */
