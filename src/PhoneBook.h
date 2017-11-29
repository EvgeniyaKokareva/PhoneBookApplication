#include "contact.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

using namespace std;


class PhoneBook{

	//private fields
	BinarySearchTree<Contact> phoneBook;

	public:
		//function prototypes
		void addNewContact(Contact&);
		void loadContactsToPhoneBook(string);
		Contact* search(Contact&);
		void printPhoneBook(Contact* = NULL);
		void filter(string, string); //Contact&
};

//add to the phone book
void PhoneBook::addNewContact(Contact& newContact){
	phoneBook.insert(newContact);
}

//load contacts from the file
void PhoneBook::loadContactsToPhoneBook(string nameOfFile){
	ifstream myfile;
	myfile.open (nameOfFile);


	if (myfile.is_open()) {   // check if we can open the file
		string contactItem;
		Contact newContact;

		while (!myfile.eof()){
			myfile >> newContact;
			phoneBook.insert(newContact);
		}
	}
	else{
		cout<<"can not find file "<< nameOfFile << endl;
	}
}

//search the phone number for given name
Contact* PhoneBook::search(Contact& contactToSearch){
	return phoneBook.search(contactToSearch);
}

//print phone book in accending order (of first name)
void PhoneBook::printPhoneBook(Contact* contact){
	int count = phoneBook.inOrder(contact);
	if (count != 1){
		cout << count << " contacts" << endl;
	}
	else {
		cout << count << " contact" << endl;
	}
}

#endif /* PHONEBOOK_H_ */
