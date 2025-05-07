#include <iostream>
#include "libmenu.hpp"
using namespace libmenu;
using namespace std;

int main() {
    Menu menu("libmenu submenu example", "1.0", {"submenu 1", "submenu 2", "info"});
    Menu submenu1("submenu 1", "", {"test 1.1", "test 1.2"}, "back to main menu");
    Menu submenu2("submenu 2", "", {"test 2.1", "test 2.2"}, "back to main menu");
    int toBreak;
    util::clear();
    while(true) {
        int menuOp;
        toBreak = 0;
        menu.printAndGetInput(menuOp, true);
        switch (menuOp) {
            case 1: {
                util::clear();
                while (!toBreak){
                    int submenu1Op;
                    submenu1.printAndGetInput(submenu1Op, true, false);
                    switch (submenu1Op) {
                        case 1: {
                            util::clear();
                            std::cout << "hello world 1\n";
                            util::sep();
                            break;
                        }
                        case 2: {
                            util::clear();
                            std::cout << "hello world 2\n";
                            util::sep();
                            break;
                        }
                        case 0: {
                            toBreak = 1;
                            break;
                        }
                        default: {
                            util::clear();
                            error::inputErr(submenu1Op);
                            util::sep();
                            break;
                        }
                    }
                }
                util::clear();
                break;
            }
            case 2: {
                util::clear();
                while (!toBreak){
                    int submenu2Op;
                    submenu2.printAndGetInput(submenu2Op, true, false);
                    switch (submenu2Op) {
                        case 1: {
                            util::clear();
                            std::cout << "hello world 3\n";
                            util::sep();
                            break;
                        }
                        case 2: {
                            util::clear();
                            std::cout << "hello world 4\n";
                            util::sep();
                            break;
                        }
                        case 0: {
                            toBreak = 1;
                            break;
                        }
                        default: {
                            util::clear();
                            error::inputErr(submenu2Op);
                            util::sep();
                            break;
                        }
                    }
                }
                util::clear();
                break;
            }
            case 3: {
                util::clear();
                std::cout << menu.getFormattedVersion() << "\n"
                << "licensed under MIT license\n";
                util::sep();
                break;
            }
            case 0: {
                util::clear();
                exit(0);
                break;
            }
            default: {
                util::clear();
                error::inputErr(menuOp);
                util::sep();
                break;
            }
        }
    }
    return 0;
}
// linux: g++ example.cpp -o example ./libmenu.so
// windows: g++ example.cpp -o example.exe ./libmenu.dll