#pragma once

#include "cinder/gl/gl.h"

namespace block_app {

    namespace visualizer {

        class Grid {
        public:
            /**
             * Creates a sketchpad.
             * (Note that sketchpad pixels are larger than screen pixels.)
             *
             * @param top_left_corner     the screen coordinates of the top left corner of
             *                            the sketchpad
             * @param num_pixels_per_side the number of sketchpad pixels in one row/column
             *                            of the sketchpad
             * @param sketchpad_size      the side length of the sketchpad, measured in
             *                            screen pixels
             */
            Grid(const glm::vec2& top_left_corner, size_t num_pixels_per_side,
                      double sketchpad_size);

            /**
             * Displays the current state of the sketchpad in the Cinder application.
             */
            void Draw() const;

        private:
            glm::vec2 top_left_corner_;

            size_t num_pixels_per_side_;

            /** Number of screen pixels in the width/height of one sketchpad pixel */
            double pixel_side_length_;
            /**Map representation of pixels in the image, and boolean to represent if it is shaded */
            std::map<std::vector<size_t>, bool> shading;

        };

    }  // namespace visualizer

}  // namespace block_app
