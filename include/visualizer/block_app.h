#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "grid.h"
#include "inventory.h"

namespace block_app {

    namespace visualizer {

        class BlockApp : public ci::app::App {
        public:
            BlockApp();

            void draw() override;
            void mouseDown(ci::app::MouseEvent event) override;
            void keyDown(ci::app::KeyEvent event) override;

            const double kWindowSize = 1000;
            const double kMargin = 200;
            const double kImageDimension = 9;

        private:
            Grid grid_;
            Inventory inventory_;
        };

    }  // namespace visualizer

}  // namespace block_app


