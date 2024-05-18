#include "StudentManagementSystem.h"
#include "menu.h"
#include <iostream>

using namespace std;

int main() {
    StudentManagementSystem system;
    bool running = true;
    int choice;
    while (running) {
        display_menu();
        cin >> choice;
        handle_choice(choice, running, system);
    }
    return 0;
}
