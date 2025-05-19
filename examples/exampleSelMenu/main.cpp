#include <iostream>
#include "../../libmenu.hpp"
using namespace libmenu;
using namespace std;

int main() {
    Menu menu("libmenu selection menu example", "1.0", {"selmenu 1", "selmenu 2", "info"});
    SelMenu selmenu1("selection menu 1:", {"test 1.1", "test 1.2"});
    SelMenu selmenu2("selection menu 2:", {"test 2.1", "test 2.2"});
    util::clear();
    while(true) {
        int menuOp;
        menu.printAndGetInput(menuOp, true);
        switch (menuOp) {
            case 1: {
                util::clear();
                    int submenu1Op;
                    selmenu1.printAndGetInput(submenu1Op, true);
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
                            util::clear();
                            break;
                        }
                        default: {
                            util::clear();
                            error::inputErr(submenu1Op);
                            util::sep();
                            break;
                        }
                    }
                break;
            }
            case 2: {
                util::clear();
                    int submenu2Op;
                    selmenu2.printAndGetInput(submenu2Op, true);
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
                            util::clear();
                            break;
                        }
                        default: {
                            util::clear();
                            error::inputErr(submenu2Op);
                            util::sep();
                            break;
                        }
                    }
                break;
            }
            case 3: {
                util::clear();
                std::cout << menu.getFormattedVersion()
                << "\nlicensed under MIT license\n";
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
// use make