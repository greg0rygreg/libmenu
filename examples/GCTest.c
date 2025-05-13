// there's only a C version because C is more low level than C++
// and thus it lets my brain release placebo-like "dopamine"
// that tricks itself into thinking it's the better option
// for memory management and testing applications
// (yes i tried to make the message as long as possible)
// GC = Game Conqueror (FOSS game memory manipulator)
#include "../libmenu.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>

int main() {
    int optionsN = 3;
    char** options = malloc(sizeof(char*) * optionsN);
    options[0] = strdup("create pointer");
    options[1] = strdup("print pointer");
    options[2] = strdup("info");
    MenuC* menu = initMenu("libmenu GameConqueror test", "1.0", options, optionsN, "exit");
    if (!menu) {error("failed to initialize menu - exiting"); return 1;}
    char* formattedV = getFormattedVersion(menu, 1);
    char* test = NULL;
    clear();
    int toBreak = 0;
    while (!toBreak) {
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
                if (test != NULL) {
                    free(test);
                }
                ignorePrev();
                char g[125];
                printf("text to save to pointer (max length of 1 kilobit): ");
                fgets(g, sizeof(g), stdin);
                test = strdup(g);
                test[strlen(test)] = '\0';
                printf("successfully made a pointer at location %p with text: %s\n", test, g);
                sep();
                break;
            }
            case 2: {
                clear();
                printf("pointer at %p says: %s\n", test, test);
                sep();
                break;
            }
            case 3: {
                clear();
                printf("%s\nlicensed under MIT license\nmade for testing purposes\n", formattedV);
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
    free(test);
    return 0;
}
// linux: g++ examples/GCTest.c -o GCTest ./libmenu.so
// windows: g++ examples/GCTest.c -o GCTest.exe ./libmenu.dll