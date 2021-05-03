//
// Created by eric on 4/25/21.
//

#include <codecvt>
#include "visualizer/inventory.h"

namespace block_app {
    namespace visualizer {
        using glm::vec2;
        Inventory::Inventory() {}

        void Inventory::Draw() const {
            vec2 top_left_corner_ = vec2(50, 725);
            vec2 bottom_right_corner_ = vec2(900, 900);
            ci::Rectf pixel_bounding_box(top_left_corner_, bottom_right_corner_);
            ci::gl::color(ci::Color("white"));
            ci::gl::drawSolidRect(pixel_bounding_box);
        }




    }
}
