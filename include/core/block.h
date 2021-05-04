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
            /**
             * Creates a Block
             * @param top_left_corner     the screen coordinates of the top left corner of
             *                            the grid
             * @param num_pixels_per_side the number of grid pixels in one row/column
             *                            of the grid
             * @param sketchpad_size      the side length of the grid, measured in
             *                            screen pixels
             */
            Block(const glm::vec2& top_left_corner, double num_pixels_per_side, double sketchpad_size);
            /**
             * Displays a block in the Cinder application.
             * @param i
             */
            void Draw(int i) const;
            /**
             * Updates the position of a block while being dragged.
             * @param event
             */
            void mouseDrag(ci::app::MouseEvent event);
        private:
            glm::vec2 top_left_corner_;
            double num_pixels_per_side_;
            double pixel_side_length_;
            std::string blocks[10];
        };
    } // namespace core
} // namespace block_app

#endif //FINAL_PROJECT_BLOCK_H
