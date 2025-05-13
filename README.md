# libmenu
facilitates the making of menus

## usage
there are 2 versions

1. C

```c
#include <stdio.h>
#include "libmenu.h"
#include <string.h>

int main() {
    int n = 2;
    char** options = (char**)malloc(sizeof(char*) * n);
    options[0] = strdup("test");
    options[1] = strdup("info");
    MenuC* menu = initMenu("libmenu general example", "1.0", options, n, "exit");
    if (!menu) {error("failed to create menu - app will exit"); return 1;}
    char* formattedV = getFormattedVersion(menu, 1);
    int b = 0; // to break or not to break
    clear();
    while(!b) {
        int menuOp;
        printAndGetInput(menu, &menuOp, 1, 1);
        switch (menuOp) {
            case 0: {
                clear();
                b++;
                break;
            }
            case 1: {
                clear();
                printf("hello world\n");
                sep();
                break;
            }
            case 2: {
                clear();
                printf("%s\nlicensed under MIT license\n", formattedV);
                sep();
                break;
            }
            default: {
                clear();
                inputErr(&menuOp);
                sep();
                break;
            }
        }
    }
    deallocMenu(menu);
    free(formattedV);
    return 0;
}
```

2. C++
```cpp
#include <iostream>
#include "libmenu.hpp"

int main() {
    libmenu::Menu menu("libmenu general example", "1.0", {"test", "info"}, "exit");
    int b = 0; // to break or not to break
    clear();
    while(!b) {
        int menuOp;
        menu.printAndGetInput(menuOp, true);
        switch (menuOp) {
            case 0: {
                libmenu::util::clear();
                b++;
                break;
            }
            case 1: {
                libmenu::util::clear();
                std::cout << "hello world\n";
                libmenu::util::sep();
                break;
            }
            case 2: {
                libmenu::util::clear();
                std::cout << menu.getFormattedVersion() << "\nlicensed under MIT license\n";
                libmenu::util::sep();
                break;
            }
            default: {
                libmenu::util::clear();
                libmenu::error::inputErr(menuOp);
                libmenu::util::sep();
                break;
            }
        }
    }
    return 0;
}
```

## TODO
- [ ] document this README