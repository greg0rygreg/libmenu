#include "libmenu.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  lm_menu *main = lm_domenu(
    "libmenu test application",
    "1.0.0",
    (char*[]){
      "submenu test",
      "pseudo-random number (1-100)",
      "info"
    },
    3,
    NULL,
    false
  );
  if (!main)
    return 1;

  lm_menu *submenu = lm_domenu(
    "submenu test options:",
    NULL,
    (char*[]){
      "say hi",
      "say hello",
      "say hey"
    },
    3,
    NULL,
    true
  );
  if (!submenu) {
    free(main);
    return 1;
  }
  bool b = false;
  bool b2 = false;
  
  lm_clear();
  while (!b) {
    lm_input(main, true);
    switch (main->last_selection) {
      case 1: {
        lm_clear();
        while (!b2) {
          lm_input(submenu, true);
          switch (submenu->last_selection) {
            case 1: {
              lm_clear();
              printf("hi\n");
              lm_sep();
              break;
            }
            case 2: {
              lm_clear();
              printf("hello\n");
              lm_sep();
              break;
            }
            case 3: {
              lm_clear();
              printf("hey\n");
              lm_sep();
              break;
            }
            case 0: {
              lm_clear();
              b2++;
              break;
            }
            default: {
              lm_clear();
              lm_error("no option made for selection %d", submenu->last_selection);
              lm_sep();
              break;
            }
          }
        }
        b2--;
        break;
      }
      case 2: {
        lm_clear();
        long c = clock();
        srand(c);
        printf("your pseudo-random number is %d (clock() -> %ld)\n", rand() % 100 + 1, c);
        lm_sep();
        break;
      }
      case 3: {
        lm_clear();
        printf("%s v. %s\nmade by greg\nlicensed under the MIT license\n", main->name, main->version);
        lm_sep();
        break;
      }
      case 0: {
        lm_clear();
        b++;
        break;
      }
      default: {
        lm_clear();
        lm_error("no option made for selection %d", main->last_selection);
        lm_sep();
        break;
      }
    }
  }
  free(main);
  free(submenu);

  return 0;
}

// gcc -o example example.c libmenu.c