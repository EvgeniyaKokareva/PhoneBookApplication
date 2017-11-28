#ifndef CONTACT_H_
#define CONTACT_H_
#include <string>

using namespace std;

class Contact{

	//private fields
	string firstName;
	string lastName;
	string phoneNumber;

	public:
	    //methods
		Contact(){}
		Contact(string, string, string);
		void setFirstName(string);
		void setLastName(string);
		void setNumber(string);

		string getFirstName();
		string getLastName();
		string getNumber();

		bool operator> (Contact);
		bool operator< (Contact);
		bool operator== (Contact);
		bool operator!= (Contact);

		friend void print(Contact&);
};

istream& operator>> (istream&, Contact&);
ostream& operator<< (ostream&, Contact&);


#endif /* CONTACT_H_ */
