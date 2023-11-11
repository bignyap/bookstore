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

void chooseAction() {

	int choice;

	std::cout << "Choose one of the menu item to proceed.." << std::endl;
	std::cout << "1. Add books to bookstore!!" << std::endl;
	std::cout << "2. Find books!!" << std::endl;
	std::cout << "3. Rent books!!" << std::endl;
	std::cout << "4. log out of application!!" << std::endl;

	std::cin >> choice;

	switch (choice) {
	case 1:
		addBooksToBookStore();
		break;
	case 2:
		findBooksInStore();
		break;
	case 3:
		rentBooksFromStore();
		break;
	case 4:
		break;
	default:
		std::cout << "Please select a valid choice." << std::endl;
	}
}

void registerUserToBookStore(const std::vector<std::vector<std::string>>& users)
{
	std::string fname, lname, email, phone, passwd;

	// Read the input
	std::cout << "Enter your first name: ";
	std::cin >> fname;
	std::cout << "Enter your last name: ";
	std::cin >> lname;
	std::cout << "Enter your email: ";
	std::cin >> email;
	std::cout << "Enter your phone number: ";
	std::cin >> phone;
	std::cout << "Enter your password: ";
	std::cin >> passwd;

	if(userExistsQ(users, email, passwd)){
		std::cout << "User already exists, try another email." << std::endl;
	}
	else{
		// Save the information to a file
		user user(fname, lname, email, phone, passwd);
		user.saveToCSV("registeredUser.csv");

		chooseAction();	
	}
	
}

void logInExistingUser(const std::vector<std::vector<std::string>>& users)
{
	std::string email, passwd;

	std::cout << "Enter your email: ";
	std::cin >> email;
	std::cout << "Enter your password: ";
	std::cin >> passwd;

	if(userExistsQ(users, email, passwd)){
		std::cout << users.size() << email << std::endl;
		std::cout << "Welcome back " << email << std::endl;
		chooseAction();
	}
	else{
		std::cout << "Sorry, no match found. Please try again!!" << std::endl;
	}
}