//
//  Screen.cpp
//  Fractal
//
//  Created by Tyler Coleman on 10/10/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include "Screen.h"

using namespace std;

Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {}

bool Screen::init() {
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }
    
    m_window = SDL_CreateWindow("Fractal Generator", SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
                                SDL_WINDOW_SHOWN);
    
    if (!m_window) {
        SDL_Quit();
        return false;
    }
    
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    
    if (!m_renderer) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
                                  SCREEN_WIDTH, SCREEN_HEIGHT);
    
    if (!m_texture) {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    
    m_buffer = new uint32_t[SCREEN_WIDTH * SCREEN_HEIGHT]; // each pixel is 32 bits (RGBA8888)
    
    memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(uint32_t));
    
    update();
    
    return true;
}

void Screen::update() {
    SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(Uint32)); // pitch is number of bytes per row of pixels
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

void Screen::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    
    uint32_t color = 0;
    color += red;
    color <<= 8;
    color += green;
    color <<=8;
    color += blue;
    color <<= 8;
    color += 0xFF;
    
    m_buffer[(y * SCREEN_WIDTH) + x] = color;
}

bool Screen::processEvents() {
    SDL_Event event;
    
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
    }
    
    return true;
}

void Screen::close() {
    delete [] m_buffer;
    
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
