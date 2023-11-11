#ifndef USER
#define USER

#include<iostream>
#include<vector>

bool compareUsers(
	const std::string& email, const std::string& passwd,
	const std::string& em, const std::string& pd
);

bool userExistsQ(
	const std::vector<std::vector<std::string>>& users, 
	const std::string& email, const std::string& passwd
);

class user {
public:
	std::string fname, lname, email, phone, passwd;
	user(
		const std::string& fn, const std::string& ln, const std::string& em, 
		const std::string& ph, const std::string& pd
	); 
	void saveToCSV(const std::string& filename);
	void print();
};

#endif