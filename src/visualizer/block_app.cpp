#include <visualizer/block_app.h>

namespace block_app {

    namespace visualizer {

        block_app::visualizer::BlockApp::BlockApp():
        grid_(glm::vec2(kMargin, kMargin), kImageDimension,
                             kWindowSize - 2 * kMargin) {
            ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
        }

        void block_app::visualizer::BlockApp::Draw() {
            ci::Color8u background_color(255, 246, 148);  // light yellow
            ci::gl::clear(background_color);

            grid_.Draw();

        }



    }  // namespace visualizer

}  // namespace block_app