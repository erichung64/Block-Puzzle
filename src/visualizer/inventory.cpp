//
// Created by eric on 4/25/21.
//

#include "visualizer/inventory.h"
namespace block_app {
    namespace visualizer {
        using glm::vec2;
        void Inventory::Draw() const {

            vec2 bottom_right_corner_ = top_left_corner_ + vec2(800, 950);
            ci::Rectf pixel_bounding_box(top_left_corner_ + vec2(200, 850), bottom_right_corner_);
            ci::gl::color(ci::Color("white"));
            ci::gl::drawSolidRect(pixel_bounding_box);
        }

        Inventory::Inventory(const vec2 &top_left_corner) {

        }
    }
}
