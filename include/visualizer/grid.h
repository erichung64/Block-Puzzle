#pragma once

#include "cinder/gl/gl.h"
#include <utility>
#include <vector>
#include <cinder/app/MouseEvent.h>
#include "core/block.h"
namespace block_app {

    namespace visualizer {

        class Grid {
        public:
            /**
             * Creates a grid.
             *
             * @param top_left_corner     the screen coordinates of the top left corner of
             *                            the grid
             * @param num_pixels_per_side the number of grid pixels in one row/column
             *                            of the grid
             * @param sketchpad_size      the side length of the grid, measured in
             *                            screen pixels
             */
            Grid(const glm::vec2& top_left_corner, double num_pixels_per_side, double sketchpad_size);

            /**
             * Displays the current state of the grid in the Cinder application.
             */
            void Draw();
            /**
             * Checks if a Row in the grid is filled.
             */
            void CheckRow();
            /**
             * Checks if a Column in the grid is filled.
             */
            void CheckCol();
            /**
             * Returns the score of the game.
             * @return int score
             */
            int returnScore();
            /**
             * Checks if a block can be placed in the grid. If not, the game is over and returns true.
             * @return bool isGameOver
             */
            bool CheckGame();
            /**
             * Checks if an integer x is within a range of numbers.
             * @param low           lower bound
             * @param high          upper bound
             * @param x             int to be checked
             * @return bool         true if x is in range
             */
            static bool inRange(int low, int high, int x);
            /**
             * Resets the score of the game.
             */
            void resetScore();
            /**
            * Shades in the grid pixels whose centers are within brush_radius units
           * of the brush's location. (One unit is equal to the length of one grid
           * pixel.)
           *
           * @param brush_screen_coords the screen coordinates at which the brush is
           *           located
           */
            bool HandleBrush(const glm::vec2& brush_screen_coords, int i);
            /**
            * Set all of the sketchpad pixels to an unshaded state.
            */
            void Clear();
            /**
             * Adds a score bonus to the player if they clear multiple lines at the same time.
             */
            void ScoreMultiplier();
            /**
             * Score of the game.
             */
            int score = 0;
            /**
             * Keeps track of which block has been clicked on. Integer corresponds to a type of block.
             */
            int block = 0;
            /**
             * Map that determines the shading of the grid.
             */
            std::map<std::vector<size_t>, bool> shading_;
            /**
             * Keeps track of number of lines cleared.
             */
            int numLinesCleared = 0;
        private:
            glm::vec2 top_left_corner_;
            double num_pixels_per_side_;
            double pixel_side_length_;

        };

    }  // namespace visualizer

}  // namespace block_app
