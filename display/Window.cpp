//
// Created by Borchers, Henry Samuel on 8/27/17.
//

#include "Window.h"
#include <iostream>
#include <sstream>

Window::Window() {

    init();


}

Window::Window(size_t width, size_t height) : height(height), width(width) {
    init();
}

int Window::init() {
    std::cout << "Initializing a window object with " << width << " by " << height << "\n";
    window = SDL_CreateWindow("My WINDOW", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int) width, (int) height,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        std::ostringstream error_message;
        error_message << "Unable to create a SDL Window. ";
        error_message << "Reason: " << SDL_GetError();
        throw std::runtime_error(error_message.str());
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == nullptr) {
        std::ostringstream error_message;
        error_message << "Unable to create an SDL renderer. ";
        error_message << "Reason: " << SDL_GetError();
        throw std::runtime_error(error_message.str());
    }
    SDL_RenderClear(renderer);

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, (int) width,
                                (int) height);
    if (texture == nullptr) {
        std::ostringstream error_message;
        error_message << "Unable to create an SDL texture. ";
        error_message << "Reason: " << SDL_GetError();
        throw std::runtime_error(error_message.str());
    }
    return 0;
}

Window::~Window() {
    std::cout << "Destroying window\n";
    SDL_DestroyWindow(window);
    window = nullptr;

    std::cout << "Destroying renderer\n";
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;

    std::cout << "Destroying texture\n";
    SDL_DestroyTexture(texture);
    texture = nullptr;

}

void Window::refresh() {
    static int dummy = 0;
    dummy++;
    poll();
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

}

void Window::poll() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            request_quit = true;

        };
    }
}

