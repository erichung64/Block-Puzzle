//
// Created by eric on 4/25/21.
//

#include <codecvt>
#include "visualizer/inventory.h"

namespace block_app {
    namespace visualizer {
        using glm::vec2;
        void Inventory::Draw() const {
            vec2 top_left_corner_ = vec2(60, 680);
            vec2 bottom_right_corner_ = vec2(980, 975);
            ci::Rectf pixel_bounding_box(top_left_corner_, bottom_right_corner_);
            ci::gl::color(ci::Color("white"));
            ci::gl::drawSolidRect(pixel_bounding_box);
            ci::gl::color(ci::Color("black"));
            ci::gl::drawStrokedRect(pixel_bounding_box);
            ci::gl::drawLine(glm::vec2(355, 680), glm::vec2(355, 975));
            ci::gl::drawLine(glm::vec2(680, 680), glm::vec2(680, 975));
        }

    }
}
