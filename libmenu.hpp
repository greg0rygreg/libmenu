#ifndef LIBMENU_HPP
#define LIBMENU_HPP
#ifdef __cplusplus
#include <string>
#include <vector>
#endif

namespace libmenu {
    //contains information about your menu
    class Menu {
        public:
        //name of the menu
        std::string name;
        //version of the menu
        std::string version;
        //options of the menu
        std::vector<std::string> options;
        //menu configurator/constructor
        Menu(std::string name, std::string version, std::vector<std::string> options, std::string exitText);
        //menu configurator/constructor
        Menu(std::string name, std::string version, std::vector<std::string> options);
        /*print the main menu and get user input and put it
        on `optionInt`
        `bool printName`: if 1, print the name of the app defined
        in your `libmenu::Menu.name` and version in `libmenu::Menu.version`
        
        else, don't print the name and version of the app

        `bool includeVersion`: defines if you want to include `libmenu::Menu.version`
        on the name "header", useful for submenus
        */
        void printAndGetInput(int &optionInt, bool printName, bool includeVersion);
        /*print the main menu and get user input and put it
        on `optionInt`
        `bool printName`: if 1, print the name of the app defined
        in your `libmenu::Menu.name` and version in `libmenu::Menu.version`
        
        else, don't print the name and version of the app*/
        void printAndGetInput(int &optionInt, bool printName);
        /*get a formatted string of the name and version of the menu

        `bool includeVersion`: defines if you want to include `libmenu::Menu.version`,
        useful for submenus
        */
        std::string getFormattedVersion(bool includeVersion);
        //get a formatted string of the name and version of the menu
        std::string getFormattedVersion();
        protected:
        //exit text
        std::string exitText = "exit";
    };
    //contains information about your selection menu
    class SelMenu {
        public:
        //name of the menu
        std::string action;
        //options of the menu
        std::vector<std::string> options;
        //menu configurator/constructor
        SelMenu(std::string action, std::vector<std::string> options, std::string cancelText);
        //menu configurator/constructor
        SelMenu(std::string action, std::vector<std::string> options);
        /*print the main menu and get user input and put it
        on `optionInt`
        `bool printName`: if 1, print the name of the app defined
        in your `libmenu::Menu.name` and version in `libmenu::Menu.version`
        
        else, don't print the name and version of the app*/
        void printAndGetInput(int &optionInt, bool printAction);
        protected:
        //cancel text
        std::string cancelText = "cancel";
    };
    namespace util {
        //clear the screen for the next operation
        void clear();
        //seperate the screen by exactly 75 equal signs
        void sep();
    }
    namespace error {
        /*print an error incase of input invalidation or something
        else*/
        void error(std::string info);
        /*print a warning incase something goes wrong and an error
        doesn't fit*/
        void warning(std::string info);
        //print an input error
        void inputErr(int input);
    }
}
#endif // libmenu_HPP
// (no compile)