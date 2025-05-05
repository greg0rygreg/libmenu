#include "libmenu.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

int main() {
    libmenu::Menu menu("libmenu example", "1.0", {"print random number", "print something", "info"});
    libmenu::clear();
    bool toBreak = 0;
    while (!toBreak) {
        srand(time(nullptr));
        int menuOp;
        menu.printAndGetInput(menuOp, true);
        switch (menuOp) {
            case 0: {
                libmenu::clear();
                toBreak = 1;
                break;
            }
            case 1: {
                libmenu::clear();
                int minN;
                int maxN;
                cout << "min number: ";
                cin >> minN;
                cout << "max number: ";
                cin >> maxN;
                libmenu::clear();
                cout << "your number is: " << rand() % maxN + minN << "\n";
                libmenu::sep();
                break;
            }
            case 2: {
                libmenu::clear();
                cin.ignore();
                string toPrint;
                cout << "text to print: ";
                getline(cin, toPrint);
                libmenu::clear();
                cout << "you typed: " << toPrint << "\n";
                libmenu::sep();
                break;
            }
            case 3: {
                libmenu::clear();
                cout << menu.getFormattedVersion() << "\n"
                << "licensed under MIT license\n";
                libmenu::sep();
                break;
            }
            default: {
                libmenu::clear();
                libmenu::error("no option made for input " + to_string(menuOp));
                libmenu::sep();
                break;
            }
        }
    }
    return 0;
}
// linux: g++ example.cpp -o example ./libmenu.so
// windows: g++ example.cpp -o example.exe ./libmenu.dll