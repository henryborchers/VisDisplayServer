//
// Created by Borchers, Henry Samuel on 8/26/17.
//

#include "catch.hpp"
#include "cmdbuffer.h"
#include <iostream>

TEST_CASE("Buffer") {
    Buffer<Command> buffer;
    REQUIRE(buffer.size() == 0);
    GIVEN("Add a command") {
        buffer.push_back(Command("My command"));
        REQUIRE(buffer.size() == 1);
        GIVEN("Get the command") {
            Command popped_command = buffer.pop_front();
            REQUIRE(popped_command.getValue() == "My command");
            REQUIRE(buffer.size() == 0);
        }

        GIVEN("Get more commands than in queue") {
            Command popped_command = buffer.pop_front();
            REQUIRE(popped_command.getValue() == "My command");
            popped_command = buffer.pop_front();
            REQUIRE(popped_command.getValue() == "");
        }
        GIVEN("The buffer can print out a stream"){
            std::cout << buffer << std::endl;
        }
    }
    GIVEN("Add a command with += operators"){
        buffer += Command("My command");
        REQUIRE(buffer.size() == 1);
        auto popped_command = buffer.pop_front();
        REQUIRE(popped_command.getValue() == "My command");
        REQUIRE(buffer.size() == 0);
    }

}