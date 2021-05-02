#include <visualizer/block_app.h>

namespace block_app {

    namespace visualizer {
        using glm::vec2;
        BlockApp::BlockApp()
                : grid_(glm::vec2(kMargin, kMargin - 100), kImageDimension, kWindowSize - 2 * kMargin, shading),
                inventory_(), block_(glm::vec2(150, 750), 4, 269),
                block1_(glm::vec2(400, 750), 4, 269),
                block2_(glm::vec2(650, 750), 4, 269){
            ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);

        }

        void BlockApp::draw() {
            ci::Color8u background_color(54, 128, 247);
            ci::gl::clear(background_color);
            ci::gl::drawStringCentered(
                    "Score: " + std::to_string(grid_.returnScore()),
                    glm::vec2(kWindowSize / 2, (kMargin - 100) / 2), ci::Color("black"));
            grid_.Draw();
            inventory_.Draw();

            block_.Draw(0);
            block1_.Draw(1);
            block2_.Draw(2);
        }

        void BlockApp::mouseUp(ci::app::MouseEvent event) {
            grid_.HandleBrush(event.getPos(), 0);
        }

        void BlockApp::keyDown(ci::app::KeyEvent event) {
            switch (event.getCode()) {
                case ci::app::KeyEvent::KEY_DELETE:
                    grid_.Clear();
                    break;
            }
        }

        void BlockApp::mouseDrag(ci::app::MouseEvent event) {
            if (clickedOn == 0) {
                block_.mouseDrag(event);
            }
            if (clickedOn == 1) {
                block1_.mouseDrag(event);
            }
            if (clickedOn == 2) {
                block2_.mouseDrag(event);
            }

        }

        void BlockApp::mouseDown(ci::app::MouseEvent event) {
            if (glm::distance(glm::vec2(event.getX(), event.getY()), glm::vec2(150, 750)) <= 50) {
                clickedOn = 0;
            } else if ((glm::distance(glm::vec2(event.getX(), event.getY()), glm::vec2(400, 750)) <= 50)) {
                clickedOn = 1;
            } else if ((glm::distance(glm::vec2(event.getX(), event.getY()), glm::vec2(650, 750)) <= 50)) {
                clickedOn = 2;
            }
        }


    }  // namespace visualizer

}  // namespace naivebayes