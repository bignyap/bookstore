#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "common.h"
#include "csvutil.h"
#include "book.h"


book::book(const std::string& n, const std::string& g, const std::string& a) {
	name = n;
	genre = g;
	author = a;
}
void book::saveToCSV(const std::string& filename) {
	// file pointer
	std::ofstream fout(filename, std::ios::out | std::ios::app);
	// Insert the data to file
	fout << name << "," << genre << "," << author << "\n";
	fout.close();
}
void book::print() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Genre: " << genre << std::endl;
	std::cout << "Author : " << author << std::endl;
}

void findBooksInStore()
{

}

void rentBooksFromStore()
{

}

void addBooksToBookStore()
{
	std::string name, genre, author;

	// Read the input
	std::cout << "Enter your book name: ";
	std::cin >> name;
	std::cout << "Enter the author name: ";
	std::cin >> author;
	std::cout << "Enter the genre: ";
	std::cin >> genre;

	// Save the information to a file
	book book(name, author, genre);
	book.saveToCSV("existingBooksList.csv");
}