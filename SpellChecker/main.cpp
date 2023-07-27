#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "DoublyLinkedBag.h" // doubly linked list bag

using namespace std;

// Function to display the bag
void displayBag(const DoublyLinkedBag<string>& bag)
{
    cout << "The dictionary contains " << bag.getCurrentSize() << " words:" << endl;

    vector<string> bagItems = bag.toVector();
    int numberOfEntries = static_cast<int>(bagItems.size());
    for (int i = 0; i < numberOfEntries; i++)
    {
        cout << bagItems[i] << " ";
    }
    cout << endl << endl;
}

// Function to check if a word is spelled correctly
void spell_check(const DoublyLinkedBag<string>& bag, const DoublyLinkedBag<string>& dict)
{
    vector<string> bagItems = bag.toVector();
    vector<string> dictItems = dict.toVector();

    cout << "The words below are spelled correctly!" << endl;
    for (vector<string>::const_iterator it = bagItems.begin(); it != bagItems.end(); ++it)
    {
        if (dict.contains(*it))
        {
            cout << *it << endl;
        }
    }
    cout << endl;

    cout << "The words below are spelled incorrectly!" << endl;
    for (vector<string>::const_iterator it = bagItems.begin(); it != bagItems.end(); ++it)
    {
        if (!dict.contains(*it))
        {
            cout << *it << endl;
        }
    }
}

int main()
{
    DoublyLinkedBag<string> bag, dict;
    string fileName, word;

    // Create dictionary using a file
    cout << "Enter the name of the file that contains words to check: ";
    cin >> fileName;
    ifstream inputFile(fileName.c_str());

    if (!inputFile)
    {
        cerr << "Error opening file " << fileName << endl;
        return 1;
    }

    while (inputFile >> word)
    {
        dict.add(word);
    }

    inputFile.close();

    cout << endl;
    cout << "Spell check any word shown in the dictionary" << endl;
    displayBag(dict);

    // User input for words to spell check
    cout << "Enter 3 words you want to spell check:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "--> ";
        cin >> word;
        bag.add(word);
    }

    cout << endl << "------" << endl;
    spell_check(bag, dict);

    return 0;
}
