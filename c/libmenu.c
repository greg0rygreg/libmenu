// i suffered to make this
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libmenu.h"

Menu* initMenu(char* name, char* version, char** options, int optionsN, char* exitText) {
    Menu* menu = malloc(sizeof(Menu));
    if (!menu) return NULL;
    menu->name = strdup(name);
    menu->version = strdup(version);
    menu->optionsN = optionsN;
    menu->options = malloc(sizeof(char*) * optionsN);
    if (!menu->options) {
        free(menu->name);
        free(menu->version);
        free(menu);
        return NULL;
    }
    for (int i = 0; i < optionsN; i++) {
        menu->options[i] = strdup(options[i]);
    }
    menu->exitText = strdup(exitText);
    return menu;
}
char* getFormattedVersion(Menu* menu, int includeVersion) {
    // PLEASE
    // NO MORE MANUAL MEMORY MANAGEMENT
    char* _temp = malloc(strlen(menu->name) + (includeVersion ? strlen(menu->version) + 5 : 1));
    if (includeVersion) {
        sprintf(_temp, "%s v. %s", menu->name, menu->version);
    } else {
        sprintf(_temp, "%s", menu->name);
    }
    return _temp;
}
void printAndGetInput(Menu* menu, int *optionInt, int printName, int includeVersion) {
    char* _temp = getFormattedVersion(menu, includeVersion);
    if (printName) {
        printf("%s\n", _temp);
    }
    for (int i = 0; i < menu->optionsN; i++) {
        printf("(%d) %s\n", i+1, menu->options[i]);
    }
    printf("(0) %s\n", menu->exitText);
    printf("\n(?) >> ");
    scanf("%d", optionInt);
    free(_temp);
}

void deallocMenu(Menu* menu) {
    for (int i = 0; i < menu->optionsN; i++) {
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
    printf("\x1b[1;31merror:\x1b[0m %s\n", info);
}
void warning(char* info) {
    printf("\x1b[1;33mwarning:\x1b[0m %s\n", info);
}
void inputErr(int *input) {
    char* _temp = malloc(25 + sizeof(*input));
    sprintf(_temp, "no option made for input %d", *input);
    error(_temp);
    free(_temp);
}
// linux: gcc libmenu.c -fPIC -shared -o libmenu.so
// windows: gcc libmenu.c -fPIC -shared -o libmenu.dll