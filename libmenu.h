#ifndef LIBMENU_H
#define LIBMENU_H
#include <stdint.h>
#include <stdbool.h>

typedef struct lm_menu {
  char **options;
  char *name;
  char *version;
  char *exit_t;
  bool submenu;
  int options_l;
  int last_selection;
} lm_menu;

lm_menu *lm_domenu(
  char *name,
  char *version,
  char **options,
  int options_l,
  char *exit_t,
  bool submenu
);

void lm_input(
  lm_menu *menu,
  bool include_name
);

void lm_sep();
void lm_clear();
void lm_noprevinput();

void lm_error(
  char *info,
  ...
);

void lm_warn(
  char *info,
  ...
);

#endif // LIBMENU_H