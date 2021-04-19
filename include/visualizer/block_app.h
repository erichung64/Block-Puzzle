//
// Created by eric on 4/19/21.
//
#ifndef FINALPROJECT_POOL_APP_H
#define FINALPROJECT_POOL_APP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "grid.h"

namespace block_app {

    namespace visualizer {

/**
 * Allows a user to draw a digit on a sketchpad and uses Naive Bayes to
 * classify it.
 */
        class BlockApp : public ci::app::App {
        public:
            BlockApp();

            void draw() override;

            const double kWindowSize = 875;
            const double kMargin = 100;
            const size_t kImageDimension = 28;

        private:
            Grid grid_;

        };

    }  // namespace visualizer

}  // namespace block_app

#endif //FINALPROJECT_POOL_APP_H
