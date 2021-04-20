//
// Created by eric on 4/19/21.
//
#include <visualizer/block_app.h>

using block_app::visualizer::BlockApp;
void prepareSettings(BlockApp::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(BlockApp, ci::app::RendererGl, prepareSettings)
