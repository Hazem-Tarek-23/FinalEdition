#include "FileHandler.h"
#include <iostream>
#include <sstream> // for data parsing

using namespace std;

FileHandler::FileHandler(const string& path) : file_path(path) {}

// Function to read student data from a file (placeholder)
void FileHandler::read_data() {
    // Implement logic to read student data from the file path
    // ... (implementation details) ...

    cout << "* Placeholder: Student data reading not implemented yet. *\n";
}

// Function to write student data to a file (placeholder)
void FileHandler::write_data() {
    // Implement logic to write student data to the file path
    // ... (implementation details) ...

    cout << "* Placeholder: Student data writing not implemented yet. *\n";
}

// Function to parse data from a file (already implemented)
vector<string> FileHandler::parse_data(const string& filename) {
    vector<string> data;
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            data.push_back(line);
        }
        file.close();
    }
    else {
        cout << "Failed to open file: " << filename << endl;
    }

    return data;
}

// Function to format and write data to a file (already implemented)
void FileHandler::format_data(const vector<int>& data, const string& filename) {
    ofstream file(filename);

    if (file.is_open()) {
        for (const int& item : data) {
            file << item << "\n";
        }

        file.close();
        cout << "Data formatted and written to file: " << filename << endl;
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
}