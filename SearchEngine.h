#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include <vector>
#include <string>
#include "Student.h"

class SearchEngine {
private:
    std::vector<Student> data;

public:
    SearchEngine() = default;
    SearchEngine(const std::vector<Student>& students) : data(students) {}

    // Methods for searching student records
    Student* search_by_id(const std::string& id);
    Student* search_by_name(const std::string& name);
    void update_data(const std::vector<Student>& students);
};

#endif // SEARCH_ENGINE_H
