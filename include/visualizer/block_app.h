#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "grid.h"
#include "inventory.h"
#include "core/block.h"
#include <random>
namespace block_app {

    namespace visualizer {

        class BlockApp : public ci::app::App {
        public:
            BlockApp();
            void setup() override;
            void draw() override;
            void mouseDown(ci::app::MouseEvent event) override;
            void mouseDrag(ci::app::MouseEvent event) override;
            void keyDown(ci::app::KeyEvent event) override;
            void mouseUp(ci::app::MouseEvent event) override;
            void generateRandomBlocks();

            const double kWindowSize = 1000;
            const double kMargin = 250;
            const double kImageDimension = 8;
            int clickedOn;
            int countBlocksPlaced = 0;
            int block1;
            int block2;
            int block3;


        private:
            Grid grid_;
            Inventory inventory_;
            core::Block block_;
            core::Block block1_;
            core::Block block2_;
            core::Block emptyBlock_;

        };

    }  // namespace visualizer

}  // namespace block_app


