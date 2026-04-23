#include "libmenu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

lm_menu *lm_domenu(
  char *name,
  char *version,
  lm_option *options,
  int options_l,
  char *exit_t,
  bool submenu
) {
  if (!options || options_l < 1) return NULL;
  lm_menu *ret = malloc(sizeof(lm_menu));
  if (!ret) return NULL;
  /*if (!exit_t) {
    if (!submenu)
      exit_t = "exit";
    else
      exit_t = "go back";
  }*/
  exit_t = !exit_t? (!submenu? "exit":"go back"):exit_t;
  ret->name = name;
  ret->version = version;
  ret->options = options;
  ret->options_l = options_l;
  ret->last = 0;
  ret->exit_t = exit_t;
  ret->submenu = submenu;

  return ret;
}

void lm_input(
  lm_menu *menu,
  bool include_name
) {
  // 4/23/26
  // if your menu prints "no option made for input -1",
  // this might be why. I didn't want libmenu to quit a
  // menu as you enter a character instead of an integer
  int tmp = -1;

  if (include_name) {
    if (menu->submenu)
      printf("%s", menu->name);
    else
      printf("%s v. %s", menu->name, menu->version);
    putchar(10);
  }

  for (int i = 0; i < menu->options_l; i++) {
    lm_option cur = menu->options[i];
    if (cur.istoggle == 0) 
      printf("[%d] %s\n", i+1, cur.key);
    else
      printf("[%d] %s [%c]\n", i+1, cur.key, *cur.togglevar? 'X':' ');
  }
  printf("[0] %s\n", menu->exit_t);
  printf("\n[...] ");

  scanf("%d", &tmp);
  menu->last = tmp;
}

void lm_sep() {
  char b[76];

  memset(b, '=', 75);
  b[75] = 0;

  printf("%s\n", b);
}

void lm_clear() {
  //printf("\x1b[2J\x1b[H");
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void lm_noprevinput() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void lm_error(
  char *info,
  ...
) {
  va_list args;
  va_start(args, info);

  printf("\x1b[1;31merror:\x1b[0m\x1b[1m ");
  vprintf(info, args);
  printf("\x1b[0m\n");

  va_end(args);
}

void lm_warn(
  char *info,
  ...
) {
  va_list args;
  va_start(args, info);

  printf("\x1b[1;33mwarning:\x1b[0m\x1b[1m ");
  vprintf(info, args);
  printf("\x1b[0m\n");

  va_end(args);
}