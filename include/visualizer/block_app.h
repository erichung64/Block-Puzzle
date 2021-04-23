#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "grid.h"
#include "block.h"

namespace block_app {

    namespace visualizer {

        class BlockApp : public ci::app::App {
        public:
            BlockApp();

            void draw() override;
            void mouseDown(ci::app::MouseEvent event) override;
            void keyDown(ci::app::KeyEvent event) override;

            const double kWindowSize = 875;
            const double kMargin = 100;
            const double kImageDimension = 9;

        private:
            Grid grid_;
            Block b;
        };

    }  // namespace visualizer

}  // namespace block_app


