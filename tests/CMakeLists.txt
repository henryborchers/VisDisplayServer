add_executable(test_buffer tests-main.cpp test_buffer.cpp catch.hpp )
add_executable(test_display_server
        catch.hpp
        tests-main.cpp
        test_display_server.cpp
        )
add_executable(test_display
        catch.hpp
        tests-main.cpp
        test_window.cpp
        )
target_link_libraries(test_buffer threadedcommand::cmdbuffer)
target_link_libraries(test_display_server threadedcommand::display)
target_link_libraries(test_display threadedcommand::display)
add_test(test_buffer test_buffer)
add_test(test_display test_display)