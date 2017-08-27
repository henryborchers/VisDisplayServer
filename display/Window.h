//
// Created by Borchers, Henry Samuel on 8/27/17.
//

#ifndef THREADEDCOMMANDS_WINDOW_H
#define THREADEDCOMMANDS_WINDOW_H

#include <SDL2/SDL.h>

class Window {
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Texture *texture = nullptr;
    size_t height = 0;
    size_t width = 0;

    int init();


    void poll();

public:
    Window(size_t width, size_t height);

    Window();

    virtual ~Window();


    void refresh();

    bool request_quit = false;
};


#endif //THREADEDCOMMANDS_WINDOW_H
