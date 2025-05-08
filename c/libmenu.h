#ifndef LIBMENU_H
#define LIBMENU_H

typedef struct {
    char* name;
    char* version;
    char** options;
    int optionsN;
    char* exitText;
} Menu;
Menu* initMenu(char* name, char* version, char** options, int optionsN, char* exitText);
char* getFormattedVersion(Menu* menu, int includeVersion);
void printAndGetInput(Menu* menu, int *optionInt, int printName, int includeVersion);
void deallocMenu(Menu* menu);
void clear();
void sep();
void error(char* info);
void warning(char* info);
void inputErr(int* input);

#endif // LIBMENU_H