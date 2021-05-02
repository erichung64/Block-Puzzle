//
// Created by eric on 5/2/21.
//

#include "core/block.h"
using glm::vec2;
block_app::core::Block::Block() {

}

void block_app::core::Block::Draw() const {
    glm::vec2 top_left_corner_ = glm::vec2(300, 900);
    vec2 pixel_top_left = top_left_corner_;
    vec2 pixel_bottom_right =
            pixel_top_left + vec2(66.66, 66.66);
    ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);
    ci::gl::drawSolidRect(pixel_bounding_box);
    ci::gl::color(ci::Color("black"));
    ci::gl::drawStrokedRect(pixel_bounding_box);
}

