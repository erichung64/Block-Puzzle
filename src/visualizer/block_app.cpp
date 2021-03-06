#include <visualizer/block_app.h>

namespace block_app {

    namespace visualizer {
        using glm::vec2;
        BlockApp::BlockApp()
                : grid_(glm::vec2(kMargin, kMargin - 100), kImageDimension, kWindowSize - 2 * kMargin),
                inventory_(),
                block_(glm::vec2(80, 700), 4, 250),
                block1_(glm::vec2(375, 700), 4, 250),
                block2_(glm::vec2(700, 700), 4, 250),
                emptyBlock_(glm::vec2(2000, 2000), 4, 250) {

        }

        void BlockApp::setup() {
            ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
            generateRandomBlocks();
        }

        void BlockApp::draw() {
            ci::Color8u background_color(54, 128, 247);
            ci::gl::clear(background_color);
            if (grid_.CheckGame()) {
                ci::gl::drawStringCentered(
                        "You Lost!",
                        glm::vec2(kWindowSize / 2, (kMargin - 100) / 2), ci::Color("white"), ci::Font("Montserrat Bold", 45));
                ci::gl::drawStringCentered(
                        "Press delete to reset the game.",
                        glm::vec2(kWindowSize / 2, (kMargin - 200) / 2), ci::Color("white"), ci::Font("Montserrat Bold", 20));
            } else {
                ci::gl::drawStringCentered(
                        "Score: " + std::to_string(grid_.returnScore()),
                        glm::vec2(kWindowSize / 2, (kMargin - 100) / 2), ci::Color("white"), ci::Font("Montserrat Bold", 45));
            }

            grid_.Draw();

            inventory_.Draw();
            if (countBlocksPlaced % 3 == 0 && countBlocksPlaced != 0) {
                generateRandomBlocks();
                countBlocksPlaced = 0;
                block_ = core::Block(glm::vec2(80, 700), 4, 250);
                block1_ = core::Block(glm::vec2(375, 700), 4, 250);
                block2_ = core::Block(glm::vec2(700, 700), 4, 250);
            }
            block_.Draw(block1);
            block1_.Draw(block2);
            block2_.Draw(block3);

        }

        void BlockApp::mouseUp(ci::app::MouseEvent event) {

            if (clickedOn == 0) {
                if (grid_.HandleBrush(event.getPos(), block1)) {
                    block_ = emptyBlock_;
                    countBlocksPlaced++;
                    clickedOn = 3;
                }
            }
            if (clickedOn == 1) {
                if (grid_.HandleBrush(event.getPos(), block2)) {
                    block1_ = emptyBlock_;
                    countBlocksPlaced++;
                    clickedOn = 3;
                }

            }
            if (clickedOn == 2) {
                if (grid_.HandleBrush(event.getPos(), block3)) {
                    block2_ = emptyBlock_;
                    countBlocksPlaced++;
                    clickedOn = 3;
                }
            }

        }

        void BlockApp::keyDown(ci::app::KeyEvent event) {
            switch (event.getCode()) {
                case ci::app::KeyEvent::KEY_DELETE:
                    grid_.Clear();
                    grid_.resetScore();
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
            if (glm::distance(glm::vec2(event.getX(), event.getY()), glm::vec2(80, 700)) <= 300) {
                clickedOn = 0;
            } else if ((glm::distance(glm::vec2(event.getX(), event.getY()), glm::vec2(375, 700)) <= 300)) {
                clickedOn = 1;
            } else if ((glm::distance(glm::vec2(event.getX(), event.getY()), glm::vec2(700, 700)) <= 300)) {
                clickedOn = 2;
            }
        }

        void BlockApp::generateRandomBlocks() {
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<int> dist(0, 8);
            block1 = dist(mt);
            block2 = dist(mt);
            block3 = dist(mt);
        }


    }  // namespace visualizer

}  // namespace block_app