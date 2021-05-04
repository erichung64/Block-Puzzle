#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "grid.h"
#include "inventory.h"
#include "core/block.h"
#include <random>
#include <core/block.h>

namespace block_app {

    namespace visualizer {

        class BlockApp : public ci::app::App {
        public:
            /**
             * Initializes a Block App.
             */
            BlockApp();
            /**
             * Sets up the window size and the initial blocks.
             */
            void setup() override;
            /**
             * Displays the current state of the Block App in the Cinder application.
             */
            void draw() override;
            /**
             * Keeps track on which block was clicked on.
             * @param event
             */
            void mouseDown(ci::app::MouseEvent event) override;
            /**
             * Updates the position of the block while being dragged.
             * @param event
             */
            void mouseDrag(ci::app::MouseEvent event) override;
            /**
             * Resets the game and clears the board when user presses Delete.
             * @param event
             */
            void keyDown(ci::app::KeyEvent event) override;
            /**
             * Places the block on to the grid, then moves the block out of the way.
             * @param event
             */
            void mouseUp(ci::app::MouseEvent event) override;
            /**
             * Generates three random blocks to be displayed.
             */
            void generateRandomBlocks();

            const double kWindowSize = 1000;
            const double kMargin = 250;
            const double kImageDimension = 8;
            //indicates which of the three blocks have been clicked on
            int clickedOn;
            //number of blocks that have been placed on the board, resets to 0 when 3 blocks have been placed
            int countBlocksPlaced = 0;
            //integer corresponding to type of block clicked on
            int block1;
            int block2;
            int block3;


        private:
            Grid grid_;
            Inventory inventory_;
            core::Block block_;
            core::Block block1_;
            core::Block block2_;
            //blocks are set to emptyBlock_ once they have been placed
            core::Block emptyBlock_;

        };

    }  // namespace visualizer

}  // namespace block_app



