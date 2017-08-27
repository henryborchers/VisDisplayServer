cmake_minimum_required(VERSION 3.9)
project(threadedCommands)
find_package(SDL2 REQUIRED)
add_subdirectory(cmdbuffer)
add_subdirectory(display)
add_executable(threadedCommands main.cpp display/display.h)
set_target_properties(threadedCommands PROPERTIES
        CXX_STANDARD 14
        CXX_EXTENSIONS ON
        )
target_link_libraries(threadedCommands threadedcommand::cmdbuffer)
target_link_libraries(threadedCommands threadedcommand::display)
enable_testing()
add_subdirectory(tests)