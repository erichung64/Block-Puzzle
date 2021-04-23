//
// Created by eric on 4/19/21.
//
#include <vector>
#include <map>
namespace block_app {
    namespace visualizer {
        class Block {
        public:
            void Draw();
            std::wstring getBlocks() {
                return reinterpret_cast<const std::basic_string<wchar_t> &>(blocks);
            }
        private:
            std::wstring blocks[7];

        };
    }
}



