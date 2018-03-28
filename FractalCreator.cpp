//
//  FractalCreater.cpp
//  Fractal
//
//  Created by Tyler Coleman on 3/19/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <memory>
#include "FractalCreator.h"
#include "assert.h"

using namespace std;

FractalCreator::FractalCreator(int width, int height) : m_width(width), m_height(height), m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}), m_fractal(new int[m_width * m_height]{0}), m_bmp(m_width, m_height), m_zoomList(m_width, m_height) {
    
    // Initialize first zoom.
    m_zoomList.add(Zoom(m_width/2, m_height/2, 4.0/m_width));
}

FractalCreator::~FractalCreator() {
    
}

void FractalCreator::run(string fileName) {
    
    calculateIteration();
    calculateTotalIterations();
    calculateRangeTotals();
    drawFractal();
    
    writeBitmap(fileName);
}

void FractalCreator::calculateIteration() {
    
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            pair<double, double> coords = m_zoomList.doZoom(x, y);
            
            int iterations = Mandelbrot::getIterations(coords.first, coords.second);
            m_fractal[y * m_width + x] = iterations;
            
            if (iterations != Mandelbrot::MAX_ITERATIONS) { // Don't want to store anything in last index.
                m_histogram[iterations]++; // Increment number of pixels with given number of iterations.
            }
        }
    }
}

void FractalCreator::drawFractal() {
    
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            int iterations = m_fractal[y * m_width + x];
            int range = getRange(iterations);
            int rangeTotal = m_rangeTotals[range];
            int rangeStart = m_ranges[range];
            
            RGB &startColor = m_colors[range];
            RGB &endColor = m_colors[range+1];
            RGB colorDiff = endColor - startColor;
            
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;
            
            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                
                int totalPixels = 0;
                
                for (int i = rangeStart; i <= iterations; i++) {
                    totalPixels += m_histogram[i];
                }
                
                red = startColor.r + colorDiff.r * (double)totalPixels/rangeTotal;
                green = startColor.g + colorDiff.g * (double)totalPixels/rangeTotal;
                blue = startColor.b + colorDiff.b * (double)totalPixels/rangeTotal;
            }
            
            m_bmp.setPixel(x, y, red, green, blue);
        }
    }
}

void FractalCreator::writeBitmap(string fileName) {
    m_bmp.write(fileName);
}

void FractalCreator::addZoom(const Zoom &zoom) {
    m_zoomList.add(zoom);
}

void FractalCreator::addRange(double rangeEnd, const RGB &rgb) {
    
    // Don't want to add a zero to totals vector the first time addRange() is called.
    if (m_bGotFirstRange) {
        m_rangeTotals.push_back(0);
    }
    
    // Set gotFirstRange flag.
    m_bGotFirstRange = true;
    
    m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
    m_colors.push_back(rgb);
}

void FractalCreator::calculateTotalIterations() {
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        m_total += m_histogram[i];
    }
}

void FractalCreator::calculateRangeTotals() {
    
    int rangeIndex = 0;
    
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        int pixels = m_histogram[i];
        
        if (i >= m_ranges[rangeIndex + 1]) {
            rangeIndex++;
        }
        
        m_rangeTotals[rangeIndex] += pixels;
    }
}

int FractalCreator::getRange(int iterations) const {
    
    int range = 0;
    for (int i = 1; i < m_ranges.size(); i++) {
        range = i;
        
        // If end of range is greater than iterations, then iterations is in that range.
        if (m_ranges[i] > iterations)
            break;
    }
    
    range--; // Decrement range so that it is zero-indexed.
    
    // Ensure range makes sense (iterations falls in some range specified by m_ranges).
    // If we run program in debug mode, assert() will crash program and give error message
    // if expression evaluates to false.
    assert(range > -1);
    assert(range < m_ranges.size());
    
    return range;
}
