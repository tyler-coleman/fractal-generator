//
//  Mandlebrot.cpp
//  Fractal
//
//  Created by Tyler Coleman on 3/14/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <stdio.h>
#include <complex>
#include "Mandelbrot.h"

using namespace std;

Mandelbrot::Mandelbrot() {
    
}

Mandelbrot::~Mandelbrot() {
    
}

int Mandelbrot::getIterations(double x, double y) {
    
    complex<double> z = 0; // Overloaded = operator sets both real and imaginary parts of z to 0.
    complex<double> c(x, y);
    
    int iterations = 0;
    
    while(iterations < MAX_ITERATIONS) {
        z = z * z + c; // Complex arithmetic implemented by <complex>.
        
        if (abs(z) > 2) break; // If z is not in the Mandlebrot set,
        iterations++;
    }
    
    return iterations;
}

