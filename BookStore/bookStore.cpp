#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "common.h"
#include "csvutil.h"
#include "user.h"
#include "book.h"
#include "action.h"
#include "bookStore.h"

void bignyaBookStore::getUsers(){
	csv userFile("registeredUser.csv");
	if(userFile.fileExistsQ()){
		allUsers = userFile.read_csv();
	}
}

void bignyaBookStore::getBooks(){
	csv bookFile("existingBooksList.csv");
	if(bookFile.fileExistsQ()){
		allBooks = bookFile.read_csv();
	}
}

void bignyaBookStore::getRents(){
	csv rentFile("bookRented.csv");
	if(rentFile.fileExistsQ()){
		allRents = rentFile.read_csv();
	}
}

bignyaBookStore::bignyaBookStore(){
	getBooks(); 
	getBooks();
	getRents();
}

void entryPoint() {

	int choice;

	std::cout << "Choose one of the menu item to proceed.." << std::endl;
	std::cout << "1. Register yourself!!" << std::endl;
	std::cout << "2. Existing user, log in!!" << std::endl;

	std::cin >> choice;

	bignyaBookStore bookStoreData;

	switch (choice) {
	case 1:
		registerUserToBookStore(bookStoreData.allUsers);
		break;
	case 2:
		logInExistingUser(bookStoreData.allUsers);
		break;
	default:
		std::cout << "Please select a valid choice." << std::endl;
	}
}

int main() {

	std::cout << "Welcome to Bignya Book Store!!!" << std::endl;
	std::cout << "*********************************************************************************" << std::endl;
	entryPoint();
	std::cin.get();
}