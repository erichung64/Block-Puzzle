//
// Created by eric on 4/19/21.
//
#include <vector>
#include <map>

namespace block_app {
    class Block {
    public:
        std::wstring blocks[7];
        Block() {
            blocks[0].append(L"....");
            blocks[0].append(L"....");
            blocks[0].append(L"XXXX");
            blocks[0].append(L"....");

            blocks[1].append(L"....");
            blocks[1].append(L".XX.");
            blocks[1].append(L".XX.");
            blocks[1].append(L"....");

            blocks[2].append(L"....");
            blocks[2].append(L"..X.");
            blocks[2].append(L".XXX");
            blocks[2].append(L"....");

            blocks[3].append(L"....");
            blocks[3].append(L".X..");
            blocks[3].append(L"XX..");
            blocks[3].append(L"....");

            blocks[4].append(L"....");
            blocks[4].append(L"....");
            blocks[4].append(L"..XX");
            blocks[4].append(L"..X.");

            blocks[5].append(L"..X.");
            blocks[5].append(L"..X.");
            blocks[5].append(L"..X.");
            blocks[5].append(L"..X.");

            blocks[6].append(L"....");
            blocks[6].append(L".X..");
            blocks[6].append(L".XX.");
            blocks[6].append(L"..X.");

            blocks[7].append(L"....");
            blocks[7].append(L"X...");
            blocks[7].append(L"XXX.");
            blocks[7].append(L"....");
        }

    private:
    };
}




