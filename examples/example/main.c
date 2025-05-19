#include "../../libmenu.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int main() {
    int optionsN = 3;
    char** options = malloc(sizeof(char*) * optionsN);
    options[0] = strdup("print random number");
    options[1] = strdup("print something");
    options[2] = strdup("info");
    Menu* menu = initMenu("libmenu example for C", "1.0", options, optionsN, "exit");
    if (!menu) {error("failed to initialize menu - exiting"); return 1;}
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