//
// Created by Borchers, Henry Samuel on 8/27/17.
//

#include "Server.h"
#include <SDL2/SDL.h>
#include <stdexcept>
#include <iostream>

Server::Server() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        throw std::runtime_error("Unable to load SDL");
    };
    std::cout << "SDL2 loaded\n";
}

Server::~Server() {
    SDL_Quit();
    std::cout << "SDL2 closed\n";
}
