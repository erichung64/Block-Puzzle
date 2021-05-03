//
// Created by eric on 4/19/21.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <visualizer/grid.h>

TEST_CASE("Test Grid") {
    const double kWindowSize = 1000;
    const double kMargin = 250;
    const double kImageDimension = 8;
    block_app::visualizer::Grid grid_ = block_app::visualizer::Grid(glm::vec2(kMargin, kMargin - 100),
                                                                    kImageDimension, kWindowSize - 2 * kMargin);
    SECTION("test checkGame") {
        REQUIRE(!grid_.CheckGame());
        for (size_t row = 0; row < (size_t)kImageDimension; ++row) {
            for (size_t col = 0; col < (size_t)kImageDimension; ++col) {

                std::vector<size_t> coordinates = {row, col};
                grid_.shading_[coordinates] = true;
            }
        }
        REQUIRE(grid_.CheckGame());
    }
    SECTION("test number is inRange") {
        REQUIRE(grid_.inRange(0, kImageDimension, 5));
        REQUIRE(!grid_.inRange(0, kImageDimension, 8));
    }
    SECTION("test score") {
        REQUIRE(grid_.returnScore() == 0);
        //shades a square
        grid_.HandleBrush(glm::vec2(300, 300), 1);
        REQUIRE(grid_.returnScore() == 4);
        grid_.HandleBrush(glm::vec2(450, 450), 0);
        REQUIRE(grid_.returnScore() == 8);
    }
}

