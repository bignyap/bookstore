#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "common.h"
#include "csvutil.h"
#include "user.h"

bool compareUsers(
	const std::string& email, const std::string& passwd,
	const std::string& em, const std::string& pd
) {
	return (
		compareStrings(email, em) &&
		compareStrings(pd, passwd)
		);
}

bool userExistsQ(
	const std::vector<std::vector<std::string>>& users, 
	const std::string& email, const std::string& passwd
){
	for (size_t i = 0; i < users.size(); ++i) {
		if (compareUsers(email, passwd, users[i][3], users[i][5])) {
			return true;
		}
	}
	return false;
}

user::user(
	const std::string& fn, const std::string& ln, const std::string& em, 
	const std::string& ph, const std::string& pd
) {
	fname = fn;
	lname = ln;
	email = em;
	phone = ph;
	passwd = pd;
}

void user::saveToCSV(const std::string& filename) {
	// file pointer
	std::ofstream fout(filename, std::ios::out | std::ios::app);
	// Insert the data to file
	fout << fname << "," << lname << "," << email << "," << phone << "," << passwd << "\n";
	fout.close();
}

void user::print() {
	std::cout << "First Name: " << fname << std::endl;
	std::cout << "Last Name: " << lname << std::endl;
	std::cout << "Email: " << email << std::endl;
	std::cout << "Phone : " << phone << std::endl;
}