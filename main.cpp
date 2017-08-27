#include <iostream>
#include <thread>
#include <cmdbuffer.h>
#include "display.h"
//#include <mutex>

#define QUIT "quit"

std::mutex mtx;



void get(Buffer<Command> &buffer, bool &sentinal) {
    std::cout << "Type \"quit\" to exit\n";
    do {
        mtx.lock();
        std::cout << ">>";
        mtx.unlock();
        std::string command;
        std::cin >> command;
        Command new_command(command);
        buffer.push_back(command);
        if (command == QUIT) {
            sentinal = false;
        }
    } while (sentinal);
}

void interpret(Buffer<Command> &buffer, std::unique_ptr<Window> &window, bool &sentinal) {
    while (sentinal) {
        window->refresh();
        if(window->request_quit){
            sentinal = false;
        }
        Command command = buffer.pop_front();
        auto value = command.getValue();
        if (value != "") {
            mtx.lock();
            std::cout << value << std::endl;
            mtx.unlock();
            if (value == QUIT) {
                sentinal = false;
            }
        }

    }
}


int main() {
    Buffer<Command> buffer;
    bool keep_active = true;
    std::unique_ptr<Window> window;
    std::cout << "Hello, World!" << std::endl;

    try {
        window = std::make_unique<Window>(640, 480);

    } catch (std::exception &e) {
        std::cerr << "Runtime Error: " << e.what();
        return EXIT_FAILURE;

    }


    std::thread getter(get, std::ref(buffer), std::ref(keep_active));
    interpret(buffer, window, keep_active);
    getter.join();
    std::cout << "Done " << buffer << std::endl;
    return 0;
}

