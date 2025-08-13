#include <stdio.h>
#include <stdlib.h>
#include "../libmenu.h"

int main() {
  char* options1[] = {"submenu 1", "submenu 2", "info"};
  char* options2[] = {"test 1.1", "test 1.2"};
  char* options3[] = {"test 2.1", "test 2.2"};
  Menu* menu = initMenu("libmenu submenus examples for C", "1.0", options1, 3, "exit");
  Menu* submenu1 = initMenu("submenu 1", "", options2, 2, "back to main menu");
  Menu* submenu2 = initMenu("submenu 2", "", options3, 2, "back to main menu");
  if (!menu || !submenu1 || !submenu2) {
    error("failed to initialize one of the menus - exiting");
    return 1;
  }
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
// use make