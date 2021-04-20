//
// Created by eric on 4/19/21.
//

#include <glm/vec2.hpp>
#include <cinder/Rect.h>
#include <cinder/gl/gl.h>
#include "visualizer/block.h"
namespace block_app {
    namespace visualizer {
        using glm::vec2;
        void Block::Draw() {
            vec2 pixel_top_left = vec2(700, 835/2);
            vec2 pixel_bottom_right = vec2(800, 835/2 + 100);
            ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);

            ci::gl::drawSolidRect(pixel_bounding_box);

            ci::gl::color(ci::Color("black"));
            ci::gl::drawStrokedRect(pixel_bounding_box);
        }
    }
}

