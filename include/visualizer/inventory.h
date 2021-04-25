//
// Created by eric on 4/25/21.
//
#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace block_app {

    namespace visualizer {
        class Inventory {
        public:
            Inventory(const glm::vec2& top_left_corner);
            void Draw() const;
        private:
            glm::vec2 top_left_corner_;
        };
    }
}

