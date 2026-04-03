#include "libmenu.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char prn[] = "pseudo-random number (1-100, last number's parity: ?)";
  lm_menu *main = lm_domenu(
    "libmenu test application",
    "1.0.0",
    (char*[]){
      "submenu test",
      prn,
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
  int lastnum = 0;
  
  lm_clear();
  while (!b) {
    prn[51] = lastnum % 2 == 0? 'E':'O';
    lm_input(main, true);
    switch (main->last) {
      case 1: {
        lm_clear();
        while (!b2) {
          lm_input(submenu, true);
          switch (submenu->last) {
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
              lm_error("no option made for selection %d", submenu->last);
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
        lastnum = rand() % 100 + 1;
        printf("your pseudo-random number is %d (clock() -> %ld)\n", lastnum, c);
        lm_sep();
        break;
      }
      case 3: {
        lm_clear();
        printf("%s v. %s\nmade by Gregory Thedore Greg\nlicensed under the MIT license\n", main->name, main->version);
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
        lm_error("no option made for selection %d", main->last);
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