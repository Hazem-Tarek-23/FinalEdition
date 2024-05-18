#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class FileHandler {
private:
	string file_path;

public:
	FileHandler(const string& path); 

	
	void read_data();

	
	void write_data();

	
	vector<string> parse_data(const string& filename);
    void format_data(const vector<int>& data, const string& filename);
};

#endif