#include <visualizer/block_app.h>

namespace block_app {

    namespace visualizer {

        BlockApp::BlockApp()
                : grid_(kImageDimension,kWindowSize - 2 * kMargin) {
            ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
        }

        void BlockApp::draw() {
            ci::Color8u background_color(255, 246, 148);  // light yellow
            ci::gl::clear(background_color);

            grid_.Draw();

            ci::gl::drawStringCentered(
                    "Press Delete to clear the sketchpad. Press Enter to make a prediction.",
                    glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("black"));

        }



    }  // namespace visualizer

}  // namespace naivebayes