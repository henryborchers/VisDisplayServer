if (SDL2_FOUND)
    add_library(display display.h Window.cpp Window.h Server.cpp Server.h)
    add_library(threadedcommand::display ALIAS display)
    set_target_properties(display PROPERTIES
            CXX_STANDARD 14
            CXX_VISIBILITY_PRESET hidden
            )

    target_include_directories(display PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(display PRIVATE SDL2)
endif ()