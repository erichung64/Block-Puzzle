//
// Created by eric on 4/19/21.
//
#ifndef FINALPROJECT_POOL_APP_H
#define FINALPROJECT_POOL_APP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace pool_app {
    namespace visualizer {
        class PoolApp : public ci::app::App{
        public:
        PoolApp();

        void draw() override;
        void update() override;

        private:

        };
    }
}



#endif //FINALPROJECT_POOL_APP_H
