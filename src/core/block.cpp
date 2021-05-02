//
// Created by eric on 5/2/21.
//

#include "core/block.h"
using glm::vec2;

block_app::core::Block::Block(const glm::vec2& top_left_corner, double num_pixels_per_side, double sketchpad_size)
        : top_left_corner_(top_left_corner),
          num_pixels_per_side_(num_pixels_per_side),
          pixel_side_length_(sketchpad_size / num_pixels_per_side) {
    blocks[0].append("....");
    blocks[0].append("....");
    blocks[0].append("XXXX");
    blocks[0].append("....");

    blocks[1].append("....");
    blocks[1].append(".XX.");
    blocks[1].append(".XX.");
    blocks[1].append("....");

    blocks[2].append("....");
    blocks[2].append("..X.");
    blocks[2].append(".XXX");
    blocks[2].append("....");

    blocks[3].append("....");
    blocks[3].append(".X..");
    blocks[3].append("XX..");
    blocks[3].append("....");

    blocks[4].append("....");
    blocks[4].append("....");
    blocks[4].append("..XX");
    blocks[4].append("..X.");

    blocks[5].append("..X.");
    blocks[5].append("..X.");
    blocks[5].append("..X.");
    blocks[5].append("..X.");

    blocks[6].append("....");
    blocks[6].append(".X..");
    blocks[6].append(".XX.");
    blocks[6].append("..X.");
}

void block_app::core::Block::Draw(int i) const {
    std::string b = blocks[i];
    for (size_t row = 0; row < num_pixels_per_side_; ++row) {
        for (size_t col = 0; col < num_pixels_per_side_; ++col) {
            if (b.at(col + row * num_pixels_per_side_) == 'X') {
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

void block_app::core::Block::mouseDrag(ci::app::MouseEvent event) {
    top_left_corner_ = event.getPos();
}

