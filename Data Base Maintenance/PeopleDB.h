#ifndef PEOPLE_DB_H
#define PEOPLE_DB_H

#include <string>
#include "BinarySearchTree.h" // Include the BinarySearchTree class

// Forward declarations of visit functions
void toScreen(People& p);
void toFile(People& p);

/**
 * @class PeopleDB
 * @brief Represents a database of people.
 *
 * The PeopleDB class provides functionality to manage a database of people.
 * It uses a BinarySearchTree to efficiently store and retrieve the people's information.
 */
class PeopleDB {
private:
    BinarySearchTree<People> db; ///< BinarySearchTree of People to store the database

public:
    /**
     * @brief Constructor.
     *
     * Creates a PeopleDB object and initializes it with data from the specified file.
     *
     * @param filename The name of the file containing the initial people list.
     */
    PeopleDB(const std::string& filename);

    /**
     * @brief Add a person to the database.
     *
     * @param person The person to add to the database.
     */
    void addPerson(const People& person);

    /**
     * @brief Remove a person from the database.
     *
     * @param name The name of the person to remove from the database.
     */
    void removePerson(const std::string& name);

    /**
     * @brief Modify a person's information in the database.
     *
     * @param name The name of the person to modify in the database.
     */
    void modifyDatabase(const std::string& name);

    /**
     * @brief Search for a person in the database.
     *
     * @param name The name of the person to search for.
     * @return True if the person is found in the database, False otherwise.
     */
    bool searchPerson(const std::string& name) const;

    /**
     * @brief Display the database in preorder (unsorted).
     */
    void displayDatabasePreorder() const;

    /**
     * @brief Display the database sorted by names.
     */
    void displayDatabaseSorted() const;

    /**
     * @brief Destructor.
     *
     * Cleans up the resources used by the PeopleDB object.
     */
    ~PeopleDB();
};

#include "PeopleDB.cpp"
#endif // PEOPLE_DB_H
