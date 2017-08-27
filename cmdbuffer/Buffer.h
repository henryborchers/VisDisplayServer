//
// Created by Borchers, Henry Samuel on 8/26/17.
//

#ifndef THREADEDCOMMANDS_BUFFERCONTAINER_H
#define THREADEDCOMMANDS_BUFFERCONTAINER_H

#include <queue>
#include <mutex>
#include <ostream>
#include <iostream>
#include <sstream>

template<class T>
class Buffer {
    std::queue<T> b_storage;
    std::mutex mtx;
public:
    void push_back(T const &item) {
        mtx.lock();
        b_storage.push(item);
        mtx.unlock();
    }

    T pop_front() {
        if (b_storage.size() > 0) {

            mtx.lock();
            T value = b_storage.front();
            b_storage.pop();
            mtx.unlock();
            return value;
        }

        return T();
    }

    size_t size() {
        mtx.lock();
        size_t s = b_storage.size();
        mtx.unlock();
        return s;
    };

    void operator+=(const T &item) {
        push_back(item);
    }

    friend std::ostream &operator<<(std::ostream &os, const Buffer<T> &buffer) {
        os << "Buffer size storage: " << buffer.b_storage.size();
        return os;
    }
    friend std::istream& operator >> (std::istream& in,  Buffer<T> &buffer){
        std::string new_command_string;
        in >> new_command_string;
        T new_command(new_command_string);
        buffer.push_back(new_command);

        return in;
    }

};


#endif //THREADEDCOMMANDS_BUFFERCONTAINER_H
