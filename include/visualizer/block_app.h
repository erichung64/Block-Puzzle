#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "grid.h"
#include "inventory.h"
#include "core/block.h"
namespace block_app {

    namespace visualizer {

        class BlockApp : public ci::app::App {
        public:
            BlockApp();

            void draw() override;
            void mouseDown(ci::app::MouseEvent event) override;
            void mouseDrag(ci::app::MouseEvent event) override;
            void keyDown(ci::app::KeyEvent event) override;
            void mouseUp(ci::app::MouseEvent event) override;

            const double kWindowSize = 1000;
            const double kMargin = 200;
            const double kImageDimension = 8;
            std::map<std::vector<size_t>, bool> shading;
            int clickedOn;
        private:
            Grid grid_;
            Inventory inventory_;
            core::Block block_;
            core::Block block1_;
            core::Block block2_;

        };

    }  // namespace visualizer

}  // namespace block_app


