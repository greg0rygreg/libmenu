#include "../../libmenu.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
using namespace libmenu;

int main() {
    Menu menu("libmenu example", "1.0", {"print random number", "print something", "info"});
    util::clear();
    bool toBreak = 0;
    while (!toBreak) {
        srand(time(nullptr));
        int menuOp;
        menu.printAndGetInput(menuOp, true);
        switch (menuOp) {
            case 0: {
                util::clear();
                toBreak = 1;
                break;
            }
            case 1: {
                util::clear();
                int minN;
                int maxN;
                cout << "min number: ";
                cin >> minN;
                cout << "max number: ";
                cin >> maxN;
                util::clear();
                cout << "your number is: " << rand() % maxN + minN << "\n";
                util::sep();
                break;
            }
            case 2: {
                util::clear();
                cin.ignore();
                string toPrint;
                cout << "text to print: ";
                getline(cin, toPrint);
                util::clear();
                cout << "you typed: " << toPrint << "\n";
                util::sep();
                break;
            }
            case 3: {
                util::clear();
                cout << menu.getFormattedVersion()
                << "\nlicensed under MIT license\n";
                util::sep();
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
// linux: g++ examples/example/main.cpp -o example ./libmenu.so
// windows: g++ examples/example/main.cpp -o example.exe ./libmenu.dll