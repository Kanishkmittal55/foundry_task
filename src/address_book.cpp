
#include "include/address_book.h"
#include <stdexcept>
#include <string>
#include <algorithm>

// The global namespace has not been polluted


// Making the find, sortByLastName and sortByFirstName method , case insensitive by converting every string to simple uppercase and then 
// performing the desired operation...!

std::string upperCase(std::string text) {
	for (int i = 0; i < text.length(); i++) {
		text[i] = toupper(text[i]);
	}
	return text;
}

void AddressBook::add(AddressBook::Entry person)

{	
	entries.push_back(person);

}

void AddressBook::remove(AddressBook::Entry person)
{
	// Your code here
	//
	// A simple iterator has been written for the erase function as it can't take objects like entries[i]
	for (std::vector<AddressBook::Entry>::iterator it = entries.begin(); it != entries.end(); ++it) {
		if (it->first_name == person.first_name && it->last_name == person.last_name && it->phone_number == person.phone_number) {
			entries.erase(it);
		}
	}

	
}


std::vector<AddressBook::Entry> AddressBook::sortedByFirstName()
{
	// Your code here
	//
	// the sort function has been used with a lamda function 
	std::sort(entries.begin(), entries.end(), [](const AddressBook::Entry& E1, const AddressBook::Entry& E2) {
		return upperCase(E1.first_name) < upperCase(E2.first_name);
		});// This makes the space complexity O(n) , considering there are n entries in the sorted list
	return entries;
}

std::vector<AddressBook::Entry> AddressBook::sortedByLastName()
{
	// Your code here
	//
	int size = entries.size();
	std::sort(entries.begin(), entries.end(), [](const AddressBook::Entry& E1, const AddressBook::Entry& E2) {
		return upperCase(E1.last_name) < upperCase(E2.last_name);
		});// This makes the space complexity O(n) , considering there are n entries in the sorted list
	return entries;

	
}

std::vector<AddressBook::Entry> AddressBook::find(const std::string &name)
{
	// Your code here
	//
	std::vector<AddressBook::Entry> newEntries;
	for (auto& entry : entries) {
		
		if (upperCase(entry.first_name) == upperCase(name) || upperCase(entry.last_name) == upperCase(name) || upperCase(entry.phone_number) == upperCase(name)) {
			newEntries.push_back(entry);
		}
	}

	return newEntries;
}

std::vector<AddressBook::Entry> AddressBook::PartialMatchFind(const std::string& name)
{
	// Your code here
	//
	std::vector<AddressBook::Entry> newEntries;
	for (auto& entry : entries) {
		int count = 0;

		for (int j = 0; j < name.length(); j++) { // As this for loop runs till the length
			//of query string, so considering the fact that any human being cannot have a first name of more than 250 characters
			// the time complexity of this function is simple linear i.e. O(n), as this inside loop will run in some constant time 
			//depending on the length of the query string.

			// Converting from member variables to simple upper case string allows the programmer to use simple accessor notation
			// to target individual characters in a string

			std::string frstName = upperCase(entry.first_name);

			//Both the strings are converted to simple strings.

			std::string toCheck = upperCase(name);

			// Then till the length of the string query i.e. if 'Dan' is entered the till length 3 , each upper case converted aplhanumeric 
			//is check against every uppercase converted alphanumeric of the query string i.e. Dan -> 'DAN'

			if (frstName[j] == toCheck[j]) {
				// A counter is incremented
				count++;
			}

			// When the entire query string is consumed i.e. counter becomes equal to the length of query string
			// which means that that every alphabet of the query string matched the entry in the memory
			// then that entry is pushed into the answers vector , which is then returned.
			if (count == name.length()) {
				newEntries.push_back(entry);
			}
		}
	}

	return newEntries;
}

