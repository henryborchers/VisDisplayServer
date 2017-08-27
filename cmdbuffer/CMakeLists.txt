add_library(cmdbuffer cmdbuffer.cpp cmdbuffer.h Buffer.h Command.cpp Command.h CommandType.h)
add_library(threadedcommand::cmdbuffer ALIAS cmdbuffer )
set_target_properties(cmdbuffer PROPERTIES
        CXX_STANDARD 14
        CXX_VISIBILITY_PRESET hidden
        )
target_include_directories(cmdbuffer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})