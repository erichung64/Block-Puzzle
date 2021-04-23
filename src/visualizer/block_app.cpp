#include <visualizer/block_app.h>

namespace block_app {

    namespace visualizer {
        using glm::vec2;
        BlockApp::BlockApp()
                : grid_(glm::vec2(kMargin, kMargin), kImageDimension, kWindowSize - 2 * kMargin) {
            ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
        }

        void BlockApp::draw() {
            ci::Color8u background_color(54, 128, 247);
            ci::gl::clear(background_color);

            grid_.Draw();
            //b.Draw();
        }

        void BlockApp::mouseDown(ci::app::MouseEvent event) {
            grid_.HandleBrush(event.getPos());
        }

        void BlockApp::keyDown(ci::app::KeyEvent event) {
            switch (event.getCode()) {
                case ci::app::KeyEvent::KEY_DELETE:
                    grid_.Clear();
                    break;
            }
        }


    }  // namespace visualizer

}  // namespace naivebayes