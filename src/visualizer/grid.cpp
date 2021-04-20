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


        void Grid::Draw() const {
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
        }



    }  // namespace visualizer

}  // namespace block_app


