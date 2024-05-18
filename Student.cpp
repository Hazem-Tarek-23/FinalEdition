#include "Student.h"

void Student::add_marks(const string& subject, int score) {
    if (num_subjects < MAX_SUBJECTS) {
        marks[num_subjects++] = { subject, score };
    }
}

void Student::display_grades() const {
    cout << "Grades for " << name << ":\n";
    for (int i = 0; i < num_subjects; ++i) {
        cout << marks[i].subject << ": " << marks[i].score << endl;
    }
}

void Student::generate_mark_sheet() const {
    cout << "Mark sheet for " << name << " (ID: " << student_id << "):\n";
    display_grades();
}

bool Student::verify_password(const string& pwd) const {
    return password == pwd;
}
