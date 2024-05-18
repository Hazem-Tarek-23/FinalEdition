#include "Student.h"
#include "StudentManagementSystem.h"
#include "SearchEngine.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool StudentManagementSystem::is_unique_id(const string& id) {
    for (int i = 0; i < num_students; ++i) {
        if (students[i].student_id == id) {
            return false;
        }
    }
    return true;
}

bool StudentManagementSystem::is_unique_password(const string& pwd) {
    for (int i = 0; i < num_students; ++i) {
        if (students[i].password == pwd) {
            return false;
        }
    }
    return true;
}

void StudentManagementSystem::add_student_record() {
    if (num_students < MAX_STUDENTS) {
        string id, name, pwd;
        cout << "Enter student ID: ";
        cin >> id;
        if (!is_unique_id(id)) {
            cout << "This ID is already taken. Please enter a unique ID.\n";
            return;
        }
        cin.ignore();
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Create a password for the student: ";
        getline(cin, pwd);
        Student new_student(id, name, pwd);
        string subjects[] = { "Math", "Science", "Physics", "Biology", "Chemistry" };
        int score;
        for (const string& subject : subjects) {
            do {
                cout << "Enter grade for " << subject << " (0-100): ";
                cin >> score;
                if (score < 0 || score > 100) {
                    cout << "Invalid grade. Please enter a value between 0 and 100.\n";
                }
            } while (score < 0 || score > 100);
            new_student.add_marks(subject, score);
        }
        students[num_students++] = new_student;
        search_engine.update_data(get_students());
        cout << "Student record added with grades.\n";
    }
    else {
        cout << "Maximum number of students reached.\n";
    }
}

void StudentManagementSystem::search_student_record() {
    string search_term, pwd;
    cout << "Enter student ID or full name to search: ";
    cin.ignore();
    getline(cin, search_term);

    Student* student = search_engine.search_by_id(search_term);
    if (!student) {
        student = search_engine.search_by_name(search_term);
    }

    if (student) {
        cout << "Enter password for " << student->name << ": ";
        getline(cin, pwd);
        if (student->verify_password(pwd)) {
            cout << "Student found: " << student->name << " with ID: " << student->student_id << endl;
            student->display_grades();
        }
        else {
            cout << "Invalid password.\n";
        }
    }
    else {
        cout << "Student not found.\n";
    }
}

void StudentManagementSystem::delete_student_record() {
    string id_to_delete;
    cout << "Enter student ID to delete: ";
    cin >> id_to_delete;
    for (int i = 0; i < num_students; ++i) {
        if (students[i].student_id == id_to_delete) {
            for (int j = i; j < num_students - 1; ++j) {
                students[j] = students[j + 1];
            }
            num_students--;
            search_engine.update_data(get_students());
            cout << "Student record deleted successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void StudentManagementSystem::modify_student_record() {
    string id_to_modify;
    cout << "Enter student ID to modify: ";
    cin >> id_to_modify;
    for (int i = 0; i < num_students; ++i) {
        if (students[i].student_id == id_to_modify) {
            int choice;
            cout << "Select what you want to modify:\n";
            cout << "1. Name\n";
            cout << "2. Password\n";
            cout << "3. Grades\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
            case 1:
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, students[i].name);
                break;
            case 2:
                cout << "Enter new password: ";
                cin.ignore();
                getline(cin, students[i].password);
                break;
            case 3:
                int score;
                for (int j = 0; j < students[i].num_subjects; ++j) {
                    cout << "Enter new grade for " << students[i].marks[j].subject << " (0-100): ";
                    cin >> score;
                    if (score < 0 || score > 100) {
                        cout << "Invalid grade. Please enter a value between 0 and 100.\n";
                        --j;
                        continue;
                    }
                    students[i].marks[j].score = score;
                }
                break;
            default:
                cout << "Invalid choice.\n";
                break;
            }
            search_engine.update_data(get_students());
            cout << "Student record modified successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void StudentManagementSystem::generate_mark_sheet() {
    string id_to_generate;
    cout << "Enter student ID to generate mark sheet: ";
    cin >> id_to_generate;
    Student* student = search_engine.search_by_id(id_to_generate);
    if (student) {
        student->generate_mark_sheet();
    }
    else {
        cout << "Student not found.\n";
    }
}


