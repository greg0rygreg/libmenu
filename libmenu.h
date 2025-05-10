#ifndef LIBMENU_H
#define LIBMENU_H
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
    //contains information about your menu
    typedef struct {
        //name of the menu
        char* name;
        //version of the menu
        char* version;
        //options of the menu
        char** options;
        //number of options of the menu
        int optionsN;
        //exit text
        char* exitText;
    } MenuC;
    //menu configurator
    MenuC* initMenu(char* name, char* version, char** options, int optionsN, char* exitText);
    /*get a formatted string of the name and version of the menu

    `int includeVersion`: defines if you want to include `Menu->version`,
    useful for submenus
    */
    char* getFormattedVersion(MenuC* menu, int includeVersion);
    /*print the main menu and get user input and put it
    on `optionInt`
    `int printName`: if 1, print the name of the app defined
    in your `Menu->name` and version in `Menu->version`

    else, don't print the name and version of the app

    `int includeVersion`: defines if you want to include `Menu->version`
    on the name "header", useful for submenus
    */
    void printAndGetInput(MenuC* menu, int *optionInt, int printName, int includeVersion);
    //deallocates a menu
    void deallocMenu(MenuC* menu);
    //clear the screen for the next operation
    void clear();
    //seperate the screen by exactly 75 equal signs
    void sep();
    /*print an error incase of input invalidation or something
    else*/
    void error(char* info);
    /*print a warning incase something goes wrong and an error
    doesn't fit*/
    void warning(char* info);
    //print an input error
    void inputErr(int* input);
    //ignore previous input incase the next one is an fgets
    inline void ignorePrev() {
        char c = getchar();
        while (c != '\n' && c != EOF);
    }
#ifdef __cplusplus
}
#endif
#endif // LIBMENU_H