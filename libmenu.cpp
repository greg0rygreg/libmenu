#include "libmenu.hpp"
#include "libmenu.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

namespace libmenu {
    Menu::Menu(std::string name, std::string version, std::vector<std::string> options, std::string exitText) {
        this->name = name;
        this->version = version;
        this->options = options;
        this->exitText = exitText;
    }
    Menu::Menu(std::string name, std::string version, std::vector<std::string> options) {
        this->name = name;
        this->version = version;
        this->options = options;
    }
    void Menu::printAndGetInput(int &optionInt, bool printName, bool includeVersion) {
        if (printName) {
            std::cout << this->getFormattedVersion(includeVersion) << "\n";
        }
        for (int i = 0; i < this->options.size(); i++) {
            std::cout << "(" << i+1 << ") " << this->options[i] << "\n";
        }
        std::cout << "(0) " << this->exitText << "\n";
        std::cout << "\n(?) >> ";
        std::cin >> optionInt;
    }
    void Menu::printAndGetInput(int &optionInt, bool printName) {
        this->printAndGetInput(optionInt, printName, 1);
    }
    std::string Menu::getFormattedVersion(bool includeVersion) {
        return this->name + (includeVersion ? " v. " + this->version : ""); // python moment
    }
    std::string Menu::getFormattedVersion() {
        return this->getFormattedVersion(1);
    }
    namespace util {
        void clear() {
            std::cout << "\x1b[2J\x1b[H";
        }
        void sep() {
            std::cout << std::string(75, '=') << "\n";
        }
    }
    namespace error {
        void error(std::string info) {
            std::cout << "\x1b[1;31merror:\x1b[0m " << info << "\n";
        }
        void warning(std::string info) {
            std::cout << "\x1b[1;33mwarning:\x1b[0m " << info << "\n";
        }
        void inputErr(int input) {
            error("no option made for input " + std::to_string(input));
        }
    }
}

extern "C" {
    MenuC* initMenu(char* name, char* version, char** options, int optionsN, char* exitText) {
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
        for (int i = 0; i < optionsN; i++) {
            menu->options[i] = strdup(options[i]);
        }
        menu->exitText = strdup(exitText);
        return menu;
    }
    char* getFormattedVersion(MenuC* menu, int includeVersion) {
        // PLEASE
        // NO MORE MANUAL MEMORY MANAGEMENT
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
        for (int i = 0; i < menu->optionsN; i++) {
            printf("(%d) %s\n", i+1, menu->options[i]);
        }
        printf("(0) %s\n", menu->exitText);
        printf("\n(?) >> ");
        scanf("%d", optionInt);
        free(_temp);
    }

    void deallocMenu(MenuC* menu) {
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
        char* _temp = (char*)malloc(25 + sizeof(*input));
        sprintf(_temp, "no option made for input %d", *input);
        error(_temp);
        free(_temp);
    }
}

// linux: g++ libmenu.cpp -fPIC -shared -o libmenu.so
// windows: g++ libmenu.cpp -fPIC -shared -o libmenu.dll
// do NOT replace g++ with gcc, it will give you linking errors