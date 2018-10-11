//
//  Screen.h
//  Fractal
//
//  Created by Tyler Coleman on 10/10/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#ifndef Screen_h
#define Screen_h

#include <SDL.h>

using namespace std;

class Screen {
    
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    uint32_t *m_buffer;
    
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;
    
    Screen();
    bool init();
    void update();
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    bool processEvents();
    void close();
};

#endif /* Screen_h */
