#include <stdio.h>
#include <stdlib.h>
#include "libmenu.h"
#include <string.h>
int main() {
    char** options1 = malloc(sizeof(char*) * 3);
    char** options2 = malloc(sizeof(char*) * 2);
    char** options3 = malloc(sizeof(char*) * 2);
    options1[0] = strdup("submenu 1");
    options1[1] = strdup("submenu 2");
    options1[2] = strdup("info");
    options2[0] = strdup("test 1.1");
    options2[1] = strdup("test 1.2");
    options3[0] = strdup("test 2.1");
    options3[1] = strdup("test 2.2");
    MenuC* menu = initMenu("libmenu submenus examples for C", "1.0", options1, 3, "exit");
    MenuC* submenu1 = initMenu("submenu 1", "", options2, 2, "back to main menu");
    MenuC* submenu2 = initMenu("submenu 2", "", options3, 2, "back to main menu");
    char* formattedV = getFormattedVersion(menu, 1);
    int toBreak;
    clear();
    while(1) {
        int menuOp;
        toBreak = 0;
        printAndGetInput(menu, &menuOp, 1, 1);
        switch (menuOp) {
            case 1: {
                clear();
                while (!toBreak){
                    int submenu1Op;
                    printAndGetInput(submenu1, &submenu1Op, 1, 0);
                    switch (submenu1Op) {
                        case 1: {
                            clear();
                            printf("hello world 1\n");
                            sep();
                            break;
                        }
                        case 2: {
                            clear();
                            printf("hello world 2\n");
                            sep();
                            break;
                        }
                        case 0: {
                            toBreak = 1;
                            break;
                        }
                        default: {
                            clear();
                            inputErr(&submenu1Op);
                            sep();
                            break;
                        }
                    }
                }
                clear();
                break;
            }
            case 2: {
                clear();
                while (!toBreak){
                    int submenu2Op;
                    printAndGetInput(submenu2, &submenu2Op, 1, 0);
                    switch (submenu2Op) {
                        case 1: {
                            clear();
                            printf("hello world 3\n");
                            sep();
                            break;
                        }
                        case 2: {
                            clear();
                            printf("hello world 4\n");
                            sep();
                            break;
                        }
                        case 0: {
                            toBreak = 1;
                            break;
                        }
                        default: {
                            clear();
                            inputErr(&submenu2Op);
                            sep();
                            break;
                        }
                    }
                }
                clear();
                break;
            }
            case 3: {
                clear();
                printf("%s\nlicensed under MIT license\n", formattedV);
                sep();
                break;
            }
            case 0: {
                deallocMenu(menu);
                deallocMenu(submenu1);
                deallocMenu(submenu2);
                free(formattedV);
                clear();
                exit(0);
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
    return 0;
}
// linux: g++ example.cpp -o example ./libmenu.so
// windows: g++ example.cpp -o example.exe ./libmenu.dll