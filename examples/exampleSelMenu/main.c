#include <stdio.h>
#include <stdlib.h>
#include "../../libmenu.h"
#include <string.h>

int main() {
    int menuN = 3, submenuN = 2;
    char** options1 = malloc(sizeof(char*) * menuN);
    char** options2 = malloc(sizeof(char*) * submenuN);
    char** options3 = malloc(sizeof(char*) * submenuN);
    options1[0] = strdup("selmenu 1");
    options1[1] = strdup("selmenu 2");
    options1[2] = strdup("info");
    options2[0] = strdup("test 1.1");
    options2[1] = strdup("test 1.2");
    options3[0] = strdup("test 2.1");
    options3[1] = strdup("test 2.2");
    Menu* menu = initMenu("libmenu selection menus examples for C", "1.0", options1, menuN, "exit");
    SelMenu* selmenu1 = initSelMenu("selection menu 1:", options2, submenuN, "cancel");
    SelMenu* selmenu2 = initSelMenu("selection menu 2:", options3, submenuN, "cancel");
    if (!menu || !selmenu1 || !selmenu2) {error("failed to initialize one of the menus - exiting"); return 1;}
    char* formattedV = getFormattedVersion(menu, 1);
    clear();
    while(1) {
        int menuOp;
        printAndGetInput(menu, &menuOp, 1, 1);
        switch (menuOp) {
            case 1: {
                clear();
                int selmenu1Op;
                getSelMenuInput(selmenu1, &selmenu1Op, 1, 1);
                switch (selmenu1Op) {
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
                        clear();
                        break;
                    }
                    default: {
                        clear();
                        inputErr(&selmenu1Op);
                        sep();
                        break;
                    }
                }
                break;
            }
            case 2: {
                clear();
                int selmenu2Op;
                getSelMenuInput(selmenu2, &selmenu2Op, 1, 1);
                switch (selmenu2Op) {
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
                        clear();
                        break;
                    }
                    default: {
                        clear();
                        inputErr(&selmenu2Op);
                        sep();
                        break;
                    }
                }
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
                deallocSelMenu(selmenu1);
                deallocSelMenu(selmenu2);
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
// use make