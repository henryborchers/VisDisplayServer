//
// Created by Borchers, Henry Samuel on 8/26/17.
//

#ifndef THREADEDCOMMANDS_COMMAND_H
#define THREADEDCOMMANDS_COMMAND_H


#include <string>
#include <CommandType.h>
class Command {
    std::string value;
    CommandType c_type;
public:
    Command(const std::string &value);

    Command();

    const std::string &getValue() const;
};


#endif //THREADEDCOMMANDS_COMMAND_H
