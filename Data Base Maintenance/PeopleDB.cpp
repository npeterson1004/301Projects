#include "PeopleDB.h"
#include <fstream>
#include <iostream>

// Constructor to initialize the database from a file
PeopleDB::PeopleDB(const std::string& filename) {
    std::ifstream inFile(filename.c_str());
    if (!inFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    People person;
    while (inFile >> person) {
        db.add(person);
    }

    inFile.close();
}

// Function to add a person to the database
void PeopleDB::addPerson(const People& person) {
    db.add(person);
}

// Function to remove a person from the database
void PeopleDB::removePerson(const std::string& name) {
    People targetPerson(name, Date());
    db.remove(targetPerson);
}

// Function to modify a person's data in the database
void PeopleDB::modifyDatabase(const std::string& name) {
    People targetPerson(name, Date());
    if (db.contains(targetPerson)) {
        std::cout << "Found this person in the database. This person's data has been removed." << std::endl;
        db.remove(targetPerson);

        std::string newName;
        Date newDate;
        std::cout << "Enter this person's new information: name and birthday (month day year): ";
        std::cin >> newName >> newDate;
        People newPerson(newName, newDate);
        db.add(newPerson);
    } else {
        std::cout << "Person not found in the database." << std::endl;
    }
}

// Function to search for a person in the database
bool PeopleDB::searchPerson(const std::string& name) const {
    People targetPerson(name, Date());
    return db.contains(targetPerson);
}

// Function to display the database using preorder traversal
void PeopleDB::displayDatabasePreorder() const {
    db.preorderTraverse(toScreen);
}

// Function to display the database in sorted order by names
void PeopleDB::displayDatabaseSorted() const {
    db.inorderTraverse(toScreen);
}

// Destructor to save the data to a file before quitting the program
PeopleDB::~PeopleDB() {
    db.inorderTraverse(toFile);

}


void toScreen(People& p)
{
    std::cout << p.getName() << " " << p.getBirthday() << std::endl;
}


