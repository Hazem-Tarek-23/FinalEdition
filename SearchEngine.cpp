#include "SearchEngine.h"

Student* SearchEngine::search_by_id(const std::string& id) {
    for (auto& student : data) {
        if (student.student_id == id) {
            return &student;
        }
    }
    return nullptr;
}

Student* SearchEngine::search_by_name(const std::string& name) {
    for (auto& student : data) {
        if (student.name == name) {
            return &student;
        }
    }
    return nullptr;
}

void SearchEngine::update_data(const std::vector<Student>& students) {
    data = students;
}
