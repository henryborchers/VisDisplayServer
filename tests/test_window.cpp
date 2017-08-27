//
// Created by Borchers, Henry Samuel on 8/27/17.
//

#include "catch.hpp"
#include "display.h"

TEST_CASE("SANITY") {
    REQUIRE(Display::sanity() == 0);
}

TEST_CASE("Window") {
    Window w(640, 480);
    GIVEN("a window object can refresh"){
        w.refresh();


    }
}