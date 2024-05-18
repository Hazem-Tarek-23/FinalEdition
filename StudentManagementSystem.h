#ifndef STUDENT_MANAGEMENT_SYSTEM_H
#define STUDENT_MANAGEMENT_SYSTEM_H

#include <vector>
#include "Student.h"
#include "SearchEngine.h"

using namespace std;

const int MAX_STUDENTS = 100;

class StudentManagementSystem {
private:
    Student students[MAX_STUDENTS];
    int num_students;
    SearchEngine search_engine;

public:
    StudentManagementSystem() : num_students(0), search_engine(get_students()) {}

    bool is_unique_id(const string& id);
    bool is_unique_password(const string& pwd);
    void add_student_record();
    void search_student_record();
    void delete_student_record();
    void modify_student_record();
    void generate_mark_sheet();

    vector<Student> get_students() const {
        return vector<Student>(students, students + num_students);
    }
};

#endif // STUDENT_MANAGEMENT_SYSTEM_H
