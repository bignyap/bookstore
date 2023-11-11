#ifndef BOOKSTORE
#define BOOKSTORE

#include<iostream>
#include<vector>
#include<string>

class bignyaBookStore {
public:
	std::vector<std::vector<std::string>> allUsers, allBooks, allRents;

	void getUsers();

	void getBooks();

	void getRents();

	bignyaBookStore();
};

void entryPoint(); 

#endif