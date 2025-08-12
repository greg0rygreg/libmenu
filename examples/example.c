#include "../libmenu.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int main() {
  char* options[3] = {"print random number", "print something", "info"};
  Menu* menu = initMenu("libmenu example for C", "1.0", options, 3, "exit");
  if (!menu) {
    error("failed to initialize menu - exiting");
    return 1;
  }
  char* formattedV = getFormattedVersion(menu, 1);
  clear();
  int toBreak = 0;
  while (!toBreak) {
    srand(time(NULL));
    int menuOp;
    printAndGetInput(menu, &menuOp, 1, 1);
    switch (menuOp) {
      case 0: {
        clear();
        toBreak = 1;
        break;
      }
      case 1: {
        clear();
        int minN;
        int maxN;
        printf("min number: ");
        scanf("%d", &minN);
        printf("max number: ");
        scanf("%d", &maxN);
        clear();
        printf("your number is: %d\n", rand() % maxN + minN);
        sep();
        break;
      }
      case 2: {
        clear();
        ignorePrev();
        char toPrint[1000];
        printf("text to print (max of 1000 chars): ");
        fgets(toPrint, sizeof(toPrint), stdin);
        clear();
        printf("you typed: %s", toPrint);
        sep();
        break;
      }
      case 3: {
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
// use make