#ifndef MENU_H
#define MENU_H
#include "StudentManagementSystem.h"

void display_menu();
void handle_choice(int choice, bool& running, StudentManagementSystem& system);

#endif // MENU_H
