#include <visualizer/grid.h>

namespace block_app {

    namespace visualizer {

        using glm::vec2;

        Grid::Grid(const glm::vec2& top_left_corner, double num_pixels_per_side, double sketchpad_size)
                : top_left_corner_(top_left_corner),
                  num_pixels_per_side_(num_pixels_per_side),
                  pixel_side_length_(sketchpad_size / num_pixels_per_side) {
            for (size_t row = 0; row < (size_t)num_pixels_per_side_; ++row) {
                for (size_t col = 0; col < (size_t)num_pixels_per_side_; ++col) {

                    std::vector<size_t> coordinates = {row, col};
                    shading_[coordinates] = false;
                }
            }
        }


        void Grid::Draw() {
            for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                    /**Shades the sketchpad according to map*/
                    std::vector<size_t> coordinates = {row, col};

                    if (shading_.at(coordinates)) {
                        ci::gl::color(ci::Color::gray(0.3f));
                    } else {
                        ci::gl::color(ci::Color("white"));
                    }

                    vec2 pixel_top_left = top_left_corner_ + vec2(col * pixel_side_length_,
                                                                  row * pixel_side_length_);

                    vec2 pixel_bottom_right =
                            pixel_top_left + vec2(pixel_side_length_, pixel_side_length_);
                    ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);

                    ci::gl::drawSolidRect(pixel_bounding_box);

                    ci::gl::color(ci::Color("black"));
                    ci::gl::drawStrokedRect(pixel_bounding_box);
                }
            }
            CheckRow();
            CheckCol();
            ScoreMultiplier();
        }

        bool Grid::HandleBrush(const vec2& brush_screen_coords, int i) {
            block = i;
            vec2 brush_sketchpad_coords =
                    (brush_screen_coords - top_left_corner_) / (float)pixel_side_length_;

            if (i == 0) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        vec2 pixel_center = {col, row};
                        if (glm::distance(brush_sketchpad_coords, pixel_center) <= .5) {
                            if (shading_[{row, col}]) {
                                return false;
                            } else if (shading_[{row, col + 1}] || !inRange(0, num_pixels_per_side_, col + 1)) {
                                return false;
                            } else if (shading_[{row, col + 2}] || !inRange(0, num_pixels_per_side_, col + 2)) {
                                return false;
                            } else if (shading_[{row, col + 3}] || !inRange(0, num_pixels_per_side_, col + 3)) {
                                return false;
                            }
                            shading_[{row, col}] = true;
                            shading_[{row, col + 1}] = true;
                            shading_[{row, col + 2}] = true;
                            shading_[{row, col + 3}] = true;
                            score += 4;
                            block = 10;
                            return true;

                        }
                    }
                }
            }
            if (i == 1) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        vec2 pixel_center = {col, row};
                        if (glm::distance(brush_sketchpad_coords, pixel_center) <= .5) {
                            if (shading_[{row, col}] ) {
                                return false;
                            } else if (shading_[{row, col + 1}] || !inRange(0, num_pixels_per_side_, col + 1)) {
                                return false;
                            } else if (shading_[{row + 1, col}] || !inRange(0, num_pixels_per_side_, row + 1)) {
                                return false;
                            } else if (shading_[{row + 1, col + 1}] || !inRange(0, num_pixels_per_side_, col + 1) || !inRange(0, num_pixels_per_side_, row + 1)) {
                                return false;
                            }
                            shading_[{row, col}] = true;
                            shading_[{row, col + 1}] = true;
                            shading_[{row + 1, col}] = true;
                            shading_[{row + 1, col + 1}] = true;
                            score += 4;
                            block = 10;
                            return true;
                        }
                    }
                }
            }
            if (i == 2) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        vec2 pixel_center = {col, row};
                        if (glm::distance(brush_sketchpad_coords, pixel_center) <= .5) {
                            if (shading_[{row, col + 1}] || !inRange(0, num_pixels_per_side_, col + 1)) {
                                return false;
                            } else if (shading_[{row + 1, col}] || !inRange(0, num_pixels_per_side_, row + 1)) {
                                return false;
                            } else if (shading_[{row + 1, col + 1}] || !inRange(0, num_pixels_per_side_, col + 1) || !inRange(0, num_pixels_per_side_, row + 1)) {
                                return false;
                            } else if (shading_[{row + 1, col + 2}] || !inRange(0, num_pixels_per_side_, col + 2) || !inRange(0, num_pixels_per_side_, row + 1)) {
                                return false;
                            }
                            shading_[{row, col + 1}] = true;
                            shading_[{row + 1, col}] = true;
                            shading_[{row + 1, col + 1}] = true;
                            shading_[{row + 1, col + 2}] = true;
                            score += 4;
                            block = 10;
                            return true;
                        }
                    }
                }
            }
            if (i == 3) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        vec2 pixel_center = {col, row};
                        if (glm::distance(brush_sketchpad_coords, pixel_center) <= .5) {
                            if (shading_[{row, col + 1}] || !inRange(0, num_pixels_per_side_, col + 1)) {
                                return false;
                            } else if (shading_[{row + 1, col}] || !inRange(0, num_pixels_per_side_, row + 1)) {
                                return false;
                            } else if (shading_[{row + 1, col + 1}] || !inRange(0, num_pixels_per_side_, col + 1) || !inRange(0, num_pixels_per_side_, row + 1)) {
                                return false;
                            }
                            shading_[{row, col + 1}] = true;
                            shading_[{row + 1, col}] = true;
                            shading_[{row + 1, col + 1}] = true;
                            score += 3;
                            block = 10;
                            return true;
                        }
                    }
                }
            }
            if (i == 4) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        vec2 pixel_center = {col, row};
                        if (glm::distance(brush_sketchpad_coords, pixel_center) <= .5) {
                            if (shading_[{row, col}]) {
                                return false;
                            } else if (shading_[{row, col + 1}] || !inRange(0, num_pixels_per_side_, col + 1)) {
                                return false;
                            } else if (shading_[{row + 1, col}] || !inRange(0, num_pixels_per_side_, row + 1)) {
                                return false;
                            }
                            shading_[{row, col}] = true;
                            shading_[{row, col + 1}] = true;
                            shading_[{row + 1, col}] = true;
                            score += 3;
                            block = 10;
                            return true;
                        }
                    }
                }
            }
            if (i == 5) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        vec2 pixel_center = {col, row};
                        if (glm::distance(brush_sketchpad_coords, pixel_center) <= .5) {
                            if (shading_[{row, col}]) {
                                return false;
                            } else if (shading_[{row + 1, col}] || !inRange(0, num_pixels_per_side_, row + 1)) {
                                return false;
                            } else if (shading_[{row + 2, col}] || !inRange(0, num_pixels_per_side_, row + 2)) {
                                return false;
                            } else if (shading_[{row + 3, col}] || !inRange(0, num_pixels_per_side_, row + 3)) {
                                return false;
                            }
                            shading_[{row, col}] = true;
                            shading_[{row + 1, col}] = true;
                            shading_[{row + 2, col}] = true;
                            shading_[{row + 3, col}] = true;
                            score += 3;
                            block = 10;
                            return true;
                        }
                    }
                }
            }
            if (i == 6) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        vec2 pixel_center = {col, row};
                        if (glm::distance(brush_sketchpad_coords, pixel_center) <= .5) {
                            if (shading_[{row, col}]) {
                                return false;
                            } else if (shading_[{row + 1, col}] || !inRange(0, num_pixels_per_side_, row + 1)) {
                                return false;
                            } else if (shading_[{row + 1, col + 1}] || !inRange(0, num_pixels_per_side_, row + 1) || !inRange(0, num_pixels_per_side_, col + 1)) {
                                return false;
                            } else if (shading_[{row + 2, col + 1}] || !inRange(0, num_pixels_per_side_, row + 2) || !inRange(0, num_pixels_per_side_, col + 1)) {
                                return false;
                            }
                            shading_[{row, col}] = true;
                            shading_[{row + 1, col}] = true;
                            shading_[{row + 1, col + 1}] = true;
                            shading_[{row + 2, col + 1}] = true;
                            score += 4;
                            block = 10;
                            return true;
                        }
                    }
                }
            }
            if (i == 7) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        vec2 pixel_center = {col, row};
                        if (glm::distance(brush_sketchpad_coords, pixel_center) <= .5) {
                            if (shading_[{row, col}]) {
                                return false;
                            } else if (shading_[{row + 1, col}] || !inRange(0, num_pixels_per_side_, row + 1)) {
                                return false;
                            } else if (shading_[{row + 2, col}] || !inRange(0, num_pixels_per_side_, row + 2)) {
                                return false;
                            } else if (shading_[{row, col + 1}] || !inRange(0, num_pixels_per_side_, col + 1)) {
                                return false;
                            } else if (shading_[{row + 1, col + 1}] || !inRange(0, num_pixels_per_side_, row + 1) || !inRange(0, num_pixels_per_side_, col + 1)) {
                                return false;
                            } else if (shading_[{row + 2, col + 1}] || !inRange(0, num_pixels_per_side_, row + 2) || !inRange(0, num_pixels_per_side_, col + 1)) {
                                return false;
                            } else if (shading_[{row, col + 2}] || !inRange(0, num_pixels_per_side_, col + 2)) {
                                return false;
                            } else if (shading_[{row + 1, col + 2}] || !inRange(0, num_pixels_per_side_, row + 1) || !inRange(0, num_pixels_per_side_, col + 2)) {
                                return false;
                            } else if (shading_[{row + 2, col + 2}] || !inRange(0, num_pixels_per_side_, row + 2) || !inRange(0, num_pixels_per_side_, col + 2)) {
                                return false;
                            }
                            shading_[{row, col}] = true;
                            shading_[{row + 1, col}] = true;
                            shading_[{row + 2, col}] = true;
                            shading_[{row, col + 1}] = true;
                            shading_[{row + 1, col + 1}] = true;
                            shading_[{row + 2, col + 1}] = true;
                            shading_[{row, col + 2}] = true;
                            shading_[{row + 1, col + 2}] = true;
                            shading_[{row + 2, col + 2}] = true;
                            score += 9;
                            block = 10;
                            return true;
                        }
                    }
                }
            }
            if (i == 8) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        vec2 pixel_center = {col, row};
                        if (glm::distance(brush_sketchpad_coords, pixel_center) <= .5) {
                            if (shading_[{row, col}]) {
                                return false;
                            }
                            shading_[{row, col}] = true;
                            score += 1;
                            block = 10;
                            return true;
                        }
                    }
                }
            }
            block = 10;
            return false;
        }


        void Grid::Clear() {
            for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                for (size_t col = 0; col < num_pixels_per_side_; ++col) {

                    std::vector<size_t> coordinates = {row, col};
                    shading_[coordinates] = false;
                }
            }
        }

        void Grid::CheckRow() {
            for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                int isFilled = 0;
                for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                    std::vector<size_t> coordinates = {row, col};
                    if (shading_.at(coordinates)) {
                        isFilled++;
                    }
                }
                if (isFilled == num_pixels_per_side_) {
                    for (size_t r = 0; r < num_pixels_per_side_; ++r) {
                        std::vector<size_t> coordinates = {row, r};
                        shading_[coordinates] = false;
                    }
                    numLinesCleared += 1;
                }
            }
        }

        void Grid::CheckCol() {
            for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                int isFilled = 0;
                for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                    std::vector<size_t> coordinates = {col, row};
                    if (shading_.at(coordinates)) {
                        isFilled++;
                    }
                }
                if (isFilled == num_pixels_per_side_) {
                    for (size_t r = 0; r < num_pixels_per_side_; ++r) {
                        std::vector<size_t> coordinates = {r, row};
                        shading_[coordinates] = false;
                    }
                    numLinesCleared += 1;
                }
            }
        }

       int Grid::returnScore() {
            return score;
        }

        bool Grid::CheckGame() {
            bool isGameOver = true;
            if (block == 0) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        if (!shading_[{row, col}] && !shading_[{row, col + 1}] && !shading_[{row, col + 2}] && !shading_[{row, col + 3}]
                        && inRange(0, num_pixels_per_side_, col + 1)
                        && inRange(0, num_pixels_per_side_, col + 2)
                        && inRange(0, num_pixels_per_side_, col + 3)) {
                            isGameOver = false;
                        }

                    }
                }
            }
            if (block == 1) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        if (!shading_[{row, col}] && !shading_[{row, col + 1}] && !shading_[{row + 1, col}] && !shading_[{row + 1, col + 1}]
                        && inRange(0, num_pixels_per_side_, col + 1)
                        && inRange(0, num_pixels_per_side_, row + 1)) {
                            isGameOver = false;
                        }

                    }
                }
            }
            if (block == 2) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        if (!shading_[{row, col + 1}] && !shading_[{row + 1, col}] && !shading_[{row + 1, col + 1}] && !shading_[{row + 1, col + 2}]
                        && inRange(0, num_pixels_per_side_, col + 1)
                        && inRange(0, num_pixels_per_side_, row + 1)
                        && inRange(0, num_pixels_per_side_, col + 2)) {
                            isGameOver = false;
                        }

                    }
                }
            }
            if (block == 3) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        if (!shading_[{row, col + 1}] && !shading_[{row + 1, col}] && !shading_[{row + 1, col + 1}]
                        && inRange(0, num_pixels_per_side_, col + 1)
                        && inRange(0, num_pixels_per_side_, row + 1)) {
                            isGameOver = false;
                        }

                    }
                }
            }
            if (block == 4) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        if (!shading_[{row, col}] && !shading_[{row + 1, col}] && !shading_[{row, col + 1}]
                        && inRange(0, num_pixels_per_side_, col + 1)
                        && inRange(0, num_pixels_per_side_, row + 1)) {
                            isGameOver = false;
                        }

                    }
                }
            }
            if (block == 5) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        if (!shading_[{row, col}] && !shading_[{row + 1, col}] && !shading_[{row + 2, col}] && !shading_[{row + 3, col}]
                        && inRange(0, num_pixels_per_side_, row + 1)
                        && inRange(0, num_pixels_per_side_, row + 2)
                        && inRange(0, num_pixels_per_side_, row + 3)) {
                            isGameOver = false;
                        }

                    }
                }
            }
            if (block == 6) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        if (!shading_[{row, col}] && !shading_[{row + 1, col}] && !shading_[{row + 1, col + 1}] && !shading_[{row + 2, col + 1}]
                        && inRange(0, num_pixels_per_side_, col + 1)
                        && inRange(0, num_pixels_per_side_, row + 1)
                        && inRange(0, num_pixels_per_side_, row + 2)) {
                            isGameOver = false;
                        }

                    }
                }
            }
            if (block == 7) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        if (!shading_[{row, col}] && !shading_[{row + 1, col}] && !shading_[{row + 2, col}] &&
                        !shading_[{row, col + 1}] && !shading_[{row + 1, col + 1}] && !shading_[{row + 2, col + 1}] &&
                        !shading_[{row, col + 2}] && !shading_[{row + 1, col + 2}] && !shading_[{row + 2, col + 2}]
                        && inRange(0, num_pixels_per_side_, row + 2)
                        && inRange(0, num_pixels_per_side_, col + 2)) {
                            isGameOver = false;
                        }

                    }
                }
            }
            if (block == 8) {
                for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                        if (!shading_[{row, col}]) {
                            isGameOver = false;
                        }

                    }
                }
            }
            if (block == 10) {
                isGameOver = false;
            }
            return isGameOver;
        }

        bool Grid::inRange(int low, int high, int x) {
            return (x-high)*(x-low) < 0;
        }

        void Grid::resetScore() {
            score = 0;
        }

        void Grid::ScoreMultiplier() {
            if (numLinesCleared == 1) {
                score = score + 10;
            } else {
                score = score + 15 * numLinesCleared;
            }
            numLinesCleared = 0;
        }
    }  // namespace visualizer

}  // namespace block_app


