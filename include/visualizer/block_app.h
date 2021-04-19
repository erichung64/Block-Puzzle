//
// Created by eric on 4/19/21.
//
#ifndef FINALPROJECT_POOL_APP_H
#define FINALPROJECT_POOL_APP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace block_app {
    namespace visualizer {
        class BlockApp : public ci::app::App{
        public:
        BlockApp();

        void draw() override;
        void update() override;
        const int kWindowSize = 875;
        const int kMargin = 100;
        private:

        };
    }
}



#endif //FINALPROJECT_POOL_APP_H
