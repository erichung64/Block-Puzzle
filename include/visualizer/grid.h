#pragma once

#include "cinder/gl/gl.h"
#include <utility>
#include <vector>
namespace block_app {

    namespace visualizer {

        class Grid {
        public:
            /**
             * Creates a grid.
             * (Note that grid pixels are larger than screen pixels.)
             *
             * @param top_left_corner     the screen coordinates of the top left corner of
             *                            the grid
             * @param num_pixels_per_side the number of sketchpad pixels in one row/column
             *                            of the grid
             * @param sketchpad_size      the side length of the grid, measured in
             *                            screen pixels
             */
            Grid(const glm::vec2& top_left_corner, double num_pixels_per_side, double sketchpad_size);

            /**
             * Displays the current state of the grid in the Cinder application.
             */
            void Draw() const;
            /**
            * Shades in the grid pixels whose centers are within brush_radius units
           * of the brush's location. (One unit is equal to the length of one grid
           * pixel.)
           *
           * @param brush_screen_coords the screen coordinates at which the brush is
           *           located
           */
            void HandleBrush(const glm::vec2& brush_screen_coords);
            /**
            * Set all of the sketchpad pixels to an unshaded state.
            */
            void Clear();
            void setShading(std::map<std::vector<size_t>, bool> s) {
                shading = std::move(s);
            }
            std::map<std::vector<size_t>, bool> getShading() {
                return shading;
            }

        private:
            glm::vec2 top_left_corner_;
            double num_pixels_per_side_;
            /** Number of screen pixels in the width/height of one sketchpad pixel */
            double pixel_side_length_;
            std::map<std::vector<size_t>, bool> shading;
        };

    }  // namespace visualizer

}  // namespace block_app