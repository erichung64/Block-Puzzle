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
                    shading[coordinates] = false;
                }
            }
        }


        void Grid::Draw() {
            for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                    /**Shades the sketchpad according to map*/
                    std::vector<size_t> coordinates = {row, col};
                    if (shading.at(coordinates)) {
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
        }

        void Grid::HandleBrush(const vec2& brush_screen_coords) {
            vec2 brush_sketchpad_coords =
                    (brush_screen_coords - top_left_corner_) / (float)pixel_side_length_;

            for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                    vec2 pixel_center = {col + 0.5, row + 0.5};
                    std::vector<size_t> coordinates = {row, col};
                    if (glm::distance(brush_sketchpad_coords, pixel_center) <= 1) {
                        shading[coordinates] = true;
                    }
                }
            }
        }
        void Grid::Clear() {
            for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                for (size_t col = 0; col < num_pixels_per_side_; ++col) {

                    std::vector<size_t> coordinates = {row, col};
                    shading[coordinates] = false;
                }
            }
        }

        void Grid::CheckRow() {
            for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                int isFilled = 0;
                for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                    std::vector<size_t> coordinates = {row, col};
                    if (shading.at(coordinates)) {
                        isFilled++;
                    }
                }
                if (isFilled == num_pixels_per_side_) {
                    for (size_t r = 0; r < num_pixels_per_side_; ++r) {
                        std::vector<size_t> coordinates = {row, r};
                        shading[coordinates] = false;
                    }
                }
            }
        }

        void Grid::CheckCol() {
            for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                int isFilled = 0;
                for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                    std::vector<size_t> coordinates = {col, row};
                    if (shading.at(coordinates)) {
                        isFilled++;
                    }
                }
                if (isFilled == num_pixels_per_side_) {
                    for (size_t r = 0; r < num_pixels_per_side_; ++r) {
                        std::vector<size_t> coordinates = {r, row};
                        shading[coordinates] = false;
                    }
                }
            }
        }


    }  // namespace visualizer

}  // namespace block_app


