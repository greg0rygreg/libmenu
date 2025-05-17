#include "libmenu.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

MenuC* initMenu(char* name, char* version, char** options, long unsigned optionsN, char* exitText) {
    MenuC* menu = (MenuC*)malloc(sizeof(MenuC));
    if (!menu) return NULL;
    menu->name = strdup(name);
    menu->version = strdup(version);
    menu->optionsN = optionsN;
    menu->options = (char**)malloc(sizeof(char*) * optionsN);
    if (!menu->options) {
        free(menu->name);
        free(menu->version);
        free(menu);
        return NULL;
    }
    for (long unsigned i = 0; i < optionsN; i++) {
        menu->options[i] = strdup(options[i]);
    }
    menu->exitText = strdup(exitText);
    return menu;
}
char* getFormattedVersion(MenuC* menu, int includeVersion) {
    char* _temp = (char*)malloc(strlen(menu->name) + (includeVersion ? strlen(menu->version) + 5 : 1));
    if (includeVersion) {
        sprintf(_temp, "%s v. %s", menu->name, menu->version);
    } else {
        sprintf(_temp, "%s", menu->name);
    }
    return _temp;
}
void printAndGetInput(MenuC* menu, int *optionInt, int printName, int includeVersion) {
    char* _temp = getFormattedVersion(menu, includeVersion);
    if (printName) {
        printf("%s\n", _temp);
    }
    for (long unsigned i = 0; i < menu->optionsN; i++) {
        printf("(%lu) %s\n", i+1, menu->options[i]);
    }
    printf("(0) %s\n", menu->exitText);
    printf("\n(?) >> ");
    scanf("%d", optionInt);
    free(_temp);
}
void deallocMenu(MenuC* menu) {
    for (long unsigned i = 0; i < menu->optionsN; i++) {
        free(menu->options[i]);
    }
    free(menu->options);
    free(menu->exitText);
    free(menu->name);
    free(menu->version);
    free(menu);
}

void clear() {
    printf("\x1b[2J\x1b[H");
}
void sep() {
    for (int i = 0; i < 75; i++) {
        printf("=");
    }
    printf("\n");
}

void error(char* info) {
    printf("\x1b[1;31merror:\x1b[0m\x1b[1m %s\x1b[0m\n", info);
}
void warning(char* info) {
    printf("\x1b[1;33mwarning:\x1b[0m\x1b[1m %s\x1b[0m\n", info);
}
void inputErr(int *input) {
    char* _temp = (char*)malloc(25 + sizeof(*input));
    sprintf(_temp, "no option made for input %d", *input);
    error(_temp);
    free(_temp);
}

// linux: gcc libmenu.c -fPIC -shared -o libmenu.so
// windows: gcc libmenu.c -fPIC -shared -o libmenu.dll
// (or check compile commands in one of the examples)