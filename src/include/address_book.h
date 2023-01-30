#pragma once
#include <iostream>
#include <string>
#include <vector>

// The global namespace has not been polluted


/// The main Address Book implementation. Extend as required.
class AddressBook
{
	
public:
	/// A container for address book data

	struct Entry
	{
		std::string first_name;
		std::string last_name;
		std::string phone_number;

	};

	// The entriesList has been declared as a member variable
	std::vector<Entry> entries;

	/// Add an entry. Implement in address_book.cpp.
	void add(Entry person);

	/// Remove an entry. Implement in address_book.cpp.
	void remove(Entry person);

	/// Return all entries sorted by first names. Implement in address_book.cpp.
	std::vector<Entry> sortedByFirstName();

	/// Return all entries sorted by last names. Implement in address_book.cpp.
	std::vector<Entry> sortedByLastName();

	/// Return all matching entries. Implement in address_book.cpp.
	std::vector<Entry> find(const std::string & name);

	// Partial Match find
	// An overloaded method could not be implemented because the method signatures cannot be change
	//, one needs a string name as a parameter to find entry or entries in the addressbook
	std::vector<Entry> PartialMatchFind(const std::string& name);
};