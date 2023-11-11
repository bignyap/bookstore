#ifndef CSVUTIL
#define CSVUTIL

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class csv {
public:
	std::string filename;

	csv (const std::string& filename0);

	bool fileExistsQ();

	void printVector(const std::vector<std::string>& vector);

	void printVector(const std::vector<std::vector<std::string>>& vector);

	void printCSV();

	std::vector<std::vector<std::string>> read_csv();
};

#endif