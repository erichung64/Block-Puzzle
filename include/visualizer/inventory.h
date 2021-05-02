//
// Created by eric on 4/25/21.
//
#pragma once

#include <core/block.h>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace block_app {

    namespace visualizer {
        class Inventory {
        public:
            Inventory();
            void Draw() const;
            const double kWindowSize = 1000;
            const double kMargin = 200;
            const double kImageDimension = 4;
        private:

            core::Block block_;
        };
    }
}

