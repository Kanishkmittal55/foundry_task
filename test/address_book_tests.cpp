#include "./address_book.h"
#include <gtest/gtest.h>
#include <string>

///  Sample test data
std::string people[][3] = {
	{"Sally", "GraHam", "+44 7700 900297"},
	{"Phoenix", "BOND", "0161 496 0311"},
	{"aaran", "pArKs", ""},
	{"Tammy", "john", "+44 888 999 1111"},
	{"JaYdeN", "Smith", "+44 131 496 0609"},
	{"ADRIANA", "Paul", "(739) 391-4868"},
	{"xamza", "Zo", "+44 131 496 0571"},
	{"Hamza", "bo", "+44 131 496 0571"},
	{"Tamara", "Joe", "+44 131 496 0571"},
	{"Patrick", "Jackman", "+44 131 496 0571"},
	{"Dan", "peters", "+44 131 236 0971"},
	{"Daniel", "Hose", "+44 132 466 0371"},

};

///  Sample test data
AddressBook AddTestPeople()
{

	AddressBook addressBook;
	// Add all of the test data to the address book
	for (auto person : people)
	{
		AddressBook::Entry entry = {person[0], person[1], person[2]};
		addressBook.add(entry);
	}
	std::cout << "Add contact test ran";
	return addressBook;
}

/// Tests that it is possible to add a person to the address book.
TEST(AddressBookTests, AddPerson)
{
	AddressBook ab;
	// Add just the first person to an empty address book
	AddressBook::Entry entry = {people[0][0], people[0][1], people[0][2]};
	ab.add(entry);

	// Get the contents of the address book
	std::vector<AddressBook::Entry> results = ab.sortedByFirstName();

	// There should only be 1 entry in the results
	ASSERT_EQ(results.size(), 1);

	// Validate that the name and phoen number is correct
	ASSERT_EQ(results[0].first_name, people[0][0]);
	ASSERT_EQ(results[0].last_name, people[0][1]);
	ASSERT_EQ(results[0].phone_number, people[0][2]);
}

/// Tests that entries are sorted by first name correctly.
TEST(AddressBookTests, SortedByFirstNames)
{
	// The correctly sorted test data
	const std::string people_sortedFirstNames[][3] = {
		{"aaran", "pArKs", ""},
		{"ADRIANA", "Paul", "(739) 391-4868"},
		{"Dan", "peters", "+44 131 236 0971"},
		{"Daniel", "Hose", "+44 132 466 0371"},
		{"Hamza", "bo", "+44 131 496 0571"},
		{"JaYdeN", "Smith", "+44 131 496 0609"},
		{"Patrick", "Jackman", "+44 131 496 0571"},
		{"Phoenix", "BOND", "0161 496 0311"},
		{"Sally", "GraHam", "+44 7700 900297"},
		{"Tamara", "Joe", "+44 131 496 0571"},
		{"Tammy", "john", "+44 888 999 1111"},
		{"xamza", "Zo", "+44 131 496 0571"}};

	// Populate the address book
	AddressBook ab = AddTestPeople();

	// Sort by first names
	std::vector<AddressBook::Entry> results = ab.sortedByFirstName();

	// There should only be 11 entries in the results
	ASSERT_EQ(results.size(), 12);

	// Validate that all of the results exactly match the desired output
	for (size_t i = 0; i < results.size(); i++)
	{
		auto personResult = results[i];
		auto personAnswer = people_sortedFirstNames[i];

		ASSERT_EQ(personResult.first_name, personAnswer[0]);
		ASSERT_EQ(personResult.last_name, personAnswer[1]);
		ASSERT_EQ(personResult.phone_number, personAnswer[2]);
	}
}

/// Tests that entries are sorted by last name correctly.
TEST(AddressBookTests, SortedByLastNames)
{
	const std::string people_sortedLastNames[][3] = {
		{"Hamza", "bo", "+44 131 496 0571"},
		{"Phoenix", "BOND", "0161 496 0311"},
		{"Sally", "GraHam", "+44 7700 900297"},
		{"Daniel", "Hose", "+44 132 466 0371"},
		{"Patrick", "Jackman", "+44 131 496 0571"},
		{"Tamara", "Joe", "+44 131 496 0571"},
		{"Tammy", "john", "+44 888 999 1111"},
		{"aaran", "pArKs", ""},
		{"ADRIANA", "Paul", "(739) 391-4868"},
		{"Dan", "peters", "+44 131 236 0971"},
		{"JaYdeN", "Smith", "+44 131 496 0609"},
		{"xamza", "Zo", "+44 131 496 0571"}};

	// To output the answers on screen
	/*for (auto& person : people_sortedLastNames) {
		cout << "Ans : " << person[0] << " " << person[1] << " " << person[2] << "\n";
	} */

	// Populate the address book
	AddressBook ab = AddTestPeople();

	// Sort by last names
	std::vector<AddressBook::Entry> results = ab.sortedByLastName();

	// There should only be 7 entries in the results
	ASSERT_EQ(results.size(), 12);

	// To output the functions test results on screen
	/* for (int i = 0; i < results.size(); i++) {
		cout << "Results : " << results[i].first_name << results[i].last_name << results[i].phone_number << "\n";
	} */

	// Validate that all of the results exactly match the desired output
	for (size_t i = 0; i < results.size(); i++)
	{
		auto personResult = results[i];
		auto personAnswer = people_sortedLastNames[i];
		ASSERT_EQ(personResult.last_name, personAnswer[1]);
		ASSERT_EQ(personResult.first_name, personAnswer[0]);

		ASSERT_EQ(personResult.phone_number, personAnswer[2]);
	}
}

/// Tests that an entry can be found in the address book.
TEST(AddressBookTests, FindPerson)
{
	// Populate the address book
	AddressBook ab = AddTestPeople();

	// Find a person whose name is, or starts with "Graham"
	std::vector<AddressBook::Entry> results = ab.find("GraHam");

	// There should only be exactly 1 entry in the results
	ASSERT_EQ(results.size(), 1);

	// Validate that the result is the entry we expected
	ASSERT_EQ(results[0].first_name, "Sally");
	ASSERT_EQ(results[0].last_name, "GraHam");
	ASSERT_EQ(results[0].phone_number, "+44 7700 900297");
}

/// Add more tests here:
///
/// TEST(AddressBookTests, YOUR_TEST_NAME)
/// {
/// 	// Perform some test logic
/// }

/// Tests that it is possible to remove a person to the address book.
TEST(AddressBookTests, removePerson)
{
	AddressBook ab;
	// Add just the first person to an empty address book
	AddressBook::Entry entry = {"Aaran", "Parks", ""};
	ab.remove(entry);

	// std::vector<AddressBook::Entry> results = ab.sortedByFirstName();

	// cout << results.size();
	//  Get the contents of the address book
	std::vector<AddressBook::Entry> results = ab.find("Aaran");

	// There should only be 1 entry in the results

	ASSERT_EQ(results.size(), 0);
}

/// Tests that an entry can be found in the address book case incensitive
TEST(AddressBookTests, FindPersonCaseInsensitive)
{
	// Populate the address book
	AddressBook ab = AddTestPeople();

	// Find a person whose name is, or starts with "Graham"
	std::vector<AddressBook::Entry> results = ab.find("gRaHaM");

	// There should only be exactly 1 entry in the results
	ASSERT_EQ(results.size(), 1);

	// Validate that the result is the entry we expected If one
	// one wants to conduct test then one must not use assert as it
	// it is case sensitive and matches the exact string and case
	// which will result in error if the argument's case is different
	// as compared to the entry's case stored in memeory.
	//
	// ASSERT_EQ(results[0].first_name, "Sally");
	// ASSERT_EQ(results[0].last_name, "GraHam");
	// ASSERT_EQ(results[0].phone_number, "+44 7700 900297");
}

/// Tests that an entry can be found in the address book in a partially matching way using first names
TEST(AddressBookTests, partialMatchFind)
{
	// Populate the address book
	AddressBook ab = AddTestPeople();

	// Find a person whose name is, or starts with "Dan"
	std::vector<AddressBook::Entry> results = ab.PartialMatchFind("Dan");

	// Find a person whose name is, or starts with "Tam"
	std::vector<AddressBook::Entry> results1 = ab.PartialMatchFind("TAM");

	// There should only be exactly 2 entry in the results
	ASSERT_EQ(results.size(), 2);

	// There should only be exactly 2 entry in the results
	ASSERT_EQ(results1.size(), 2);

	// Validate that the result is the entry we expected If one
	// one wants to conduct test then one must not use ASSERT_EQ as it
	// it is case sensitive and matches the exact string and case
	// which will result in error if the argument's case is different
	// as compared to the entry's case stored in memeory.
	//
	// ASSERT_EQ(results[0].first_name, "Sally");
	// ASSERT_EQ(results[0].last_name, "GraHam");
	// ASSERT_EQ(results[0].phone_number, "+44 7700 900297");
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}