//
// Created by eric on 4/19/21.
//

#include "visualizer/grid.h"
namespace block_app {
    namespace visualizer {
        block_app::visualizer::Grid::Grid(const vec2& top_left_corner, size_t num_pixels_per_side,
                                          double sketchpad_size)
                : top_left_corner_(top_left_corner),
                  num_pixels_per_side_(num_pixels_per_side),
                  pixel_side_length_(sketchpad_size / num_pixels_per_side) {

        }



        void block_app::visualizer::Grid::Draw() const {
            for (size_t row = 0; row < num_pixels_per_side_; ++row) {
                for (size_t col = 0; col < num_pixels_per_side_; ++col) {
                    // Currently, this will draw a quarter circle centered at the top-left
                    // corner with a radius of 20

                    // TODO: Replace the if-statement below with an if-statement that checks
                    // if the pixel at (row, col) is currently shaded
                    ci::gl::color(ci::Color("white"));
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
    }
}


