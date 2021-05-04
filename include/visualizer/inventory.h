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
            /**
             * Displays the inventory in the Cinder Application.
             */
            void Draw() const;
        private:
        };
    }
}

