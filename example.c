#include "libmenu.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  lm_menu *main = make_menu(
    "libmenu 2.0.0 test application",
    "1.0.0",
  (char*[]){
    "submenu test",
    "pseudo-random number (1-100)",
    "info"
  },
  3,
  "exit",
  false
  );
  if (!main)
    return 1;

  lm_menu *submenu = make_menu(
    "submenu test options:",
    NULL,
  (char*[]){
    "say hi",
    "say hello",
    "say hey"
  },
  3,
  "go back",
  true
  );
  if (!submenu) {
    free(main);
    return 1;
  }
  bool b = false;
  bool b2 = false;
  
  clear();
  while (!b) {
    get_input(main, true);
    switch (main->last_selection) {
      case 1: {
        clear();
        while (!b2) {
          get_input(submenu, true);
          switch (submenu->last_selection) {
            case 1: {
              clear();
              printf("hi\n");
              sep();
              break;
            }
            case 2: {
              clear();
              printf("hello\n");
              sep();
              break;
            }
            case 3: {
              clear();
              printf("hey\n");
              sep();
              break;
            }
            case 0: {
              clear();
              b2++;
              break;
            }
            default: {
              clear();
              error("no option made for selection %d", submenu->last_selection);
              sep();
              break;
            }
          }
        }
        b2--;
        break;
      }
      case 2: {
        clear();
        long c = clock();
        srand(c);
        printf("your pseudo-random number is %d (clock() -> %ld)\n", rand() % 100 + 1, c);
        sep();
        break;
      }
      case 3: {
        clear();
        printf("%s v. %s\nmade by Greg\nlicensed under the MIT license\n", main->name, main->version);
        sep();
        break;
      }
      case 0: {
        clear();
        b++;
        break;
      }
      default: {
        clear();
        error("no option made for selection %d", main->last_selection);
        sep();
        break;
      }
    }
  }
  free(main);
  free(submenu);

  return 0;
}

// gcc -o example example.c libmenu.c