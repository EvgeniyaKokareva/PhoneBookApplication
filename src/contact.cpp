#include "contact.h"
#include <iostream>

using namespace std;

//constructor
Contact::Contact(string fn, string ln, string number){
	firstName = fn;
	lastName = ln;
	phoneNumber = number;
}

//setters
void Contact::setFirstName(string fn){
	firstName = fn;
}

void Contact::setLastName(string ln){
	lastName = ln;
}

void Contact::setNumber(string number){
	phoneNumber = number;
}

//getters
string Contact::getFirstName(){
	return firstName;
}

string Contact::getLastName(){
	return lastName;
}

string Contact::getNumber(){
	return phoneNumber;
}

//operator overload
bool Contact::operator>(Contact other){
	if (this->getFirstName() != other.getFirstName()){
		return this->getFirstName() > other.getFirstName();
	}
	else{
		return this->getLastName() > other.getLastName();
	}
}

bool Contact::operator<(Contact other){
	if (this->getFirstName() != other.getFirstName()){
		return this->getFirstName() < other.getFirstName();
	}
	else{
		return this->getLastName() < other.getLastName();
	}
}
bool Contact::operator==(Contact other){
	return this->getLastName() == other.getLastName() && this->getFirstName() == other.getFirstName();
}

bool Contact::operator!=(Contact other){
	return this->getLastName() != other.getLastName() || this->getFirstName() != other.getFirstName();
}

istream& operator>> (istream& iStream, Contact& contact)
{
	string item;
	iStream >> item;
	contact.setFirstName(item);
	iStream >> item;
	contact.setLastName(item);
	iStream >> item;
	contact.setNumber(item);

	return iStream;
}

ostream& operator<< (ostream& oStream, Contact& contact)
{
	oStream << contact.getFirstName() << " " << contact.getLastName() << ": ";
	oStream << contact.getNumber() << endl;

	return oStream;
}


