#include "PhoneBook.h"
#include "contact.h"
#include <iostream>
#include <ctime>
using namespace std;

//function prototypes
string toUpper (string);
bool validateStringInput(string);
bool validateNumberInput(string);
string firstNameInput();
string lastNameInput();
string phoneNumberInput();


//sample run program
int main() {

	char choice;
	string input;

	//create phone book
	PhoneBook myPhoneBook;

	cout << "***MY	PHONEBOOK	APPLICATION***" << endl;

	//create choice menu
	while(choice != 'Q') {
		cout << endl;
		cout << "\nPlease	choose	an	operation:" << endl;
		cout << "A (Add) | L (Load) | S (Search) | P(Print) | F(Filter) | Q(Quit): ";
		getline (cin, input);
		choice = toupper(input[0]);

		switch (choice){
			case 'A':
				{
					//create new contact
					Contact newContact;
					newContact.setFirstName(firstNameInput());
					newContact.setLastName(lastNameInput());
					newContact.setNumber(phoneNumberInput());
					//add new contact to book
					myPhoneBook.addNewContact(newContact);
				}break;

			case 'L':
				{
					cout << "Enter file name: ";
					getline(cin, input);

					myPhoneBook.loadContactsToPhoneBook(input);
				}break;

			case 'S':
				{
					Contact* foundContact;
					Contact newContact;
					newContact.setFirstName(firstNameInput());
					newContact.setLastName(lastNameInput());
// count the search time
//					clock_t begin = clock();
//
//					int number_of_iterations = 1000000;
//
//					for(int i = 0; i < number_of_iterations; i++){
						foundContact = myPhoneBook.search(newContact);
//					}
//
//					clock_t end = clock();
//					double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
//					cout << "search time for " << number_of_iterations << " iterations is " << elapsed_secs << endl;

					if (foundContact == NULL){
						cout << "contact is not found" << endl;
					}
					else {
						cout << "number: " << foundContact->getNumber();
					}
				}break;

			case 'P':
				{
					myPhoneBook.printPhoneBook();
				}break;

			case 'F':
				{
					Contact newContact;
					newContact.setFirstName(firstNameInput());
					newContact.setLastName(lastNameInput());

					myPhoneBook.printPhoneBook(&newContact);
				}break;

			case'Q':
				cout << "Bye" << endl;
				break;
			default:
				{
					cout << "invalid input. try again" << endl;
				}break;
		}
	}


	return 0;
}

//turn all letters to upper case
string toUpper (string input){
	for(uint i = 0; i < input.length(); i++){
		input[i] = toupper(input[i]);
	}
	return input;
}

//check the input for only letters
bool validateStringInput(string input){
	bool goodInput = true;
	for(uint i = 0; i < input.length(); i++){
		if(!isalpha(input[i])){
			goodInput = false;
			return goodInput;
		}
	}
	return goodInput;
}

//check input for only numbers
bool validateNumberInput(string input){
	bool isGoodInput = true;
	for(uint i = 0; i < input.length(); i++){
		if(isalpha(input[i])){
			isGoodInput = false;
			break;
		}
	}
	return isGoodInput;
}

//ask user to input the first name, validate input
string firstNameInput(){
	string input;
	bool isGoodInput = false;

	do{
		cout << "\nEnter first name: ";
		getline(cin, input);
		input = toUpper(input);

		//validate input
		isGoodInput = validateStringInput(input);
		if (isGoodInput != true){
			cout << "wrong input. try again" << endl;
		}
	}while (isGoodInput != true);

	return input;
}

//ask user to input the last name, validate input
string lastNameInput(){
	string input;
	bool isGoodInput = false;

	do{
		cout << "\nEnter last name: ";
		getline(cin, input);
		input = toUpper(input);

		//validate input
		isGoodInput = validateStringInput(input);

		if (isGoodInput != true){
			cout << "wrong input. try again" << endl;
		}
	}while (isGoodInput != true);

	return input;
}

//ask user to input the phone number, validate input
string phoneNumberInput(){
	bool isGoodInput = false;
	string input;

	while (isGoodInput == false){
		cout << endl;
		cout << "Enter phone number: ";
		getline (cin, input);
		//validate input
		isGoodInput = validateNumberInput(input);
		if (isGoodInput != true){
			cout << "wrong input. try again" << endl;
		}
	}
	return input;
}
