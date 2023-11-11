#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "csvutil.h"


csv::csv (const std::string& filename0) 
{
	filename = filename0;
}

bool csv::fileExistsQ() {
	std::ifstream ifile;
	ifile.open(filename);
	if (ifile) {
		return true;
	}
	else {
		return false;
	}
}

void csv::printVector(const std::vector<std::string>& vector) {
	for (auto i = vector.begin(); i != vector.end(); ++i) {
		std::cout << *i << std::endl;
	}
}

void csv::printVector(const std::vector<std::vector<std::string>>& vector) {
	for (auto i = vector.begin(); i != vector.end(); ++i) {
		printVector(*i);
	}
}

void csv::printCSV() 
{
	if (fileExistsQ()) 
	{
		std::vector<std::vector<std::string>> vec = read_csv();
		printVector(vec);
	}
	else
		std::cout << "File does not exist!!" << std::endl;
}

std::vector<std::vector<std::string>> csv::read_csv() {
	std::vector<std::vector<std::string>> content;
	std::vector<std::string> row;
	std::string line, word;
	std::fstream file(filename, std::ios::in);
	if (file.is_open()) {
		while (std::getline(file, line)) {
			row.clear();
			std::stringstream str(line);
			while (std::getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	return content;
}