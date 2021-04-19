//
// Created by eric on 4/19/21.
//
#include <visualizer/pool_app.h>

using pool_app::visualizer::PoolApp;

void prepareSettings(PoolApp::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(PoolApp, ci::app::RendererGl, prepareSettings)
