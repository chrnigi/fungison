#ifndef MENU_H
#define MENU_H
// Must match functionptr-array.
typedef enum MENU 
{
    menu_start,
    menu_dependencies,
    menu_checkdeps,
    MENU_END
} MENU;

typedef struct MenuItem 
{
    MENU id;
    char key;
    size_t subMenucount;
    MENU *subMenus;
    // REPLACE MAGIC NUMBERS
    char name[128];
    char desc[1024];
    char help[256];
    // REPLACE MAGIC NUMBERS
} MenuItem;

void exec_menu(MENU menu_id);

/*                  AVOIDING NAMING CONFLICTS
*   
*  To avoid naming conflicts with enum MENU, and menu functions,
*  any function should have the name of the corresponding enumeration,
*  with a prefixed _
*
*/

/* Menus with submenus */

/* Menus without submenus */
void _menu_checkdeps(void);

#endif

#ifdef MENU_SRC // Declare static function pointer array only in menu.c
static void (*menu_funcs[MENU_END])(void) = {
    NULL,           // menu_start
    NULL,           // menu_dependencies
    &_menu_checkdeps,

};
// Pad array


static MenuItem menus[MENU_END] = {
    {menu_start, 's', 1, {menu_dependencies,}, "Start Menu", "This is the start menu.", "Help text"},
    {menu_dependencies, 'd', 1, {menu_checkdeps,}, "Dependencies", "Check if necessary dependencies are installed.", "Help text"},
    {menu_checkdeps, 'd', 0, {0}, "", "", ""},
    
};

#endif