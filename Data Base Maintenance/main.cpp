/**
 * @file main.cpp
 * @brief Implementation of the xxx database system.
 *
 * This program is an implementation of a database system to manage information
 * about people. The system allows users to perform various operations on the
 * database, including adding, removing, modifying, searching, and displaying
 * information about people. The data includes each person's name and birthday.
 *
 *  *
 * @author Nathan Peterson
 * StartID: QW3581YM
 * Prof: Jie Meichnser
 */

#include <iostream>
#include <fstream>
#include <string>
#include "People.h"
#include "PeopleDB.h"


using namespace std;

// Visit function to save data to a file
void toFile(People& p) {
    std::ofstream fsOut("studentDB2.txt", std::ios_base::app);
    fsOut << p << std::endl;
    fsOut.close();
}

int main() {
    std::string filename;
    std::cout << "Welcome to xxx database system. Please enter the file that contains initial people list: ";
    std::cin >> filename;

    // Create a PeopleDB object and initialize it with the data from the specified file
    PeopleDB peopleDatabase(filename.c_str());

    int option;
    do {
        // Display the available options to the user
        std::cout << "Please enter your option:" << std::endl;
        std::cout << "1. add a new person" << std::endl;
        std::cout << "2. remove a person" << std::endl;
        std::cout << "3. modify the database" << std::endl;
        std::cout << "4. search for a person in the database" << std::endl;
        std::cout << "5. display the database" << std::endl;
        std::cout << "6. display the database sorted by names" << std::endl;
        std::cout << "7. quit and save the database to a file" << std::endl;
        std::cout << "--> ";
        std::cin >> option;

        switch (option) {
            case 1: {
                // Option 1: Add a new person to the database
                std::string name;
                Date birthday;

                std::cout << "To add, enter name and birthday (month day year): ";
                std::cin >> name >> birthday;

                People newPerson(name, birthday);
                peopleDatabase.addPerson(newPerson);

                char addAnother;
                std::cout << "Add another one? (Y/N): ";
                std::cin >> addAnother;
                while (tolower(addAnother) == 'y') {
                    std::cout << "To add, enter name and birthday (month day year): ";
                    std::cin >> name >> birthday;
                    People anotherPerson(name, birthday);
                    peopleDatabase.addPerson(anotherPerson);

                    std::cout << "Add another one? (Y/N): ";
                    std::cin >> addAnother;
                }
                break;
            }
            case 2: {
                // Option 2: Remove a person from the database
                std::string name;
                std::cout << "To remove, enter a name: ";
                std::cin >> name;
                peopleDatabase.removePerson(name);

                char removeAnother;
                std::cout << "Remove another one? (Y/N): ";
                std::cin >> removeAnother;
                while (tolower(removeAnother) == 'y') {
                    std::cout << "To remove, enter a name: ";
                    std::cin >> name;
                    peopleDatabase.removePerson(name);

                    std::cout << "Remove another one? (Y/N): ";
                    std::cin >> removeAnother;
                }
                break;
            }
            case 3: {
                // Option 3: Modify a person's information in the database
                std::string name;
                std::cout << "To modify, enter person's name: ";
                std::cin >> name;
                peopleDatabase.modifyDatabase(name);

                char modifyAnother;
                std::cout << "Continue to modify? (Y/N): ";
                std::cin >> modifyAnother;
                while (tolower(modifyAnother) == 'y') {
                    std::cout << "To modify, enter person's name: ";
                    std::cin >> name;
                    peopleDatabase.modifyDatabase(name);

                    std::cout << "Continue to modify? (Y/N): ";
                    std::cin >> modifyAnother;
                }
                break;
            }
            case 4: {
                // Option 4: Search for a person in the database
                std::string name;
                std::cout << "To search, enter person's name: ";
                std::cin >> name;
                if (peopleDatabase.searchPerson(name)) {
                    std::cout << "Found the person in the database! ";
                    People foundPerson(name, Date());
                    cout << foundPerson.getName() << endl;
                    peopleDatabase.displayDatabasePreorder();
                } else {
                    std::cout << "Can not find." << std::endl;
                }

                char searchAnother;
                std::cout << "Continue another search? (Y/N): ";
                std::cin >> searchAnother;
                while (tolower(searchAnother) == 'y') {
                    std::cout << "To search, enter person's name: ";
                    std::cin >> name;
                    if (peopleDatabase.searchPerson(name)) {
                        std::cout << "Found the person in the database!";
                        People foundPerson(name, Date());
                        cout << foundPerson.getName()  << endl;
                        peopleDatabase.displayDatabasePreorder();
                    } else {
                        std::cout << "Can not find." << std::endl;
                    }

                    std::cout << "Continue another search? (Y/N): ";
                    std::cin >> searchAnother;
                }
                break;
            }
            case 5: {
                // Option 5: Display the database in preorder (unsorted)
                std::cout << "The database displayed using preorder (not sorted):" << std::endl;
                peopleDatabase.displayDatabasePreorder();
                break;
            }
            case 6: {
                // Option 6: Display the database sorted by names
                std::cout << "The database displayed in sorted order by names:" << std::endl;
                peopleDatabase.displayDatabaseSorted();
                break;
            }
            case 7: {
                // Option 7: Quit and save the database to a file
                std::cout << "The updated database has been saved to “studentDB2.txt”." << std::endl;
                break;
            }
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
                break;
        }
    } while (option != 7);

    std::cout << "Bye!" << std::endl;

    return 0;
}
