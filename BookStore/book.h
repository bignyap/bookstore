#ifndef BOOK
#define BOOK

#include<iostream>
#include<string>


class book {
public:
	std::string name, genre, author;
	book(const std::string& n, const std::string& g, const std::string& a);
	void saveToCSV(const std::string& filename);
	void print();
};

void findBooksInStore();

void rentBooksFromStore();

void addBooksToBookStore();

#endif