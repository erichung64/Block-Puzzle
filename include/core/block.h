//
// Created by eric on 5/2/21.
//

#ifndef FINAL_PROJECT_BLOCK_H
#define FINAL_PROJECT_BLOCK_H

#include <cinder/app/MouseEvent.h>
#include "cinder/gl/gl.h"
#include <utility>
#include <vector>
namespace block_app {
    namespace core {
        class Block {
        public:
            Block(const glm::vec2& top_left_corner, double num_pixels_per_side, double sketchpad_size);
            void Draw(int i) const;
            void mouseDrag(ci::app::MouseEvent event);

        private:
            glm::vec2 top_left_corner_;
            double num_pixels_per_side_;
            double pixel_side_length_;
            std::string blocks[7];
        };
    }
}



#endif //FINAL_PROJECT_BLOCK_H
