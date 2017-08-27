//
// Created by Borchers, Henry Samuel on 8/26/17.
//

#include "Command.h"

Command::Command(const std::string &value)
        : value(value),
          c_type(CommandType::unevalued)
{}

Command::Command()
        : c_type(CommandType::noop) {
    value = "";
}

const std::string &Command::getValue() const {
    return value;
}

