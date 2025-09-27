#include <iostream>
#include <string>

  using namespace std;

#include "src/where.hpp"

int main() {
  bool run = true; //Controls while loop
  string inputString; //Store user's input string
  int choice = -1; //Initialize with invalid choice

  cout << "What string would you like to use as your input?" << endl;
  getline(cin, inputString); //Reading user input

  //Creating a menu here
  while (run) {
    cout << "Awesome! Would you like to search for a character or substring? \n"
    << "1. Character \n"
    << "2. Substring \n"
    << "3. Exit \n"
    << "Enter your choice: "
    << endl;

    cin >> choice; //Store user choice

    if (cin.fail()) {
      cin.clear(); //Clear the error message
      cin.ignore(); //Flush the buffer

      cout << "Invalid input. Please enter 1, 2, or 3." << endl;

    } else if (choice == 3) {
      cout << "Bye bye!" << endl;
      run = false; //Kills the while-loop, exits program
    } else if (choice == 1) { //Character search block
      char charSearch;
      cin.ignore(); //Remove the leftover newline so the menu prompt waits
      cout << "Enter a character to search for: ";
      cin >> charSearch; //This will only work if the user inputs a single character, handling gibberish after that is annoying
      int charIndex = find(inputString, charSearch); //Calls the find function and stores the return value

      if (charIndex != -1) {
        cout << "Character '" << charSearch << "' found at index: " << charIndex << endl;
      } else {
        cout << "Character '" << charSearch << "' not found. " << endl;
      }

    } else if (choice == 2) { //Substring search block
      string substrSearch;
      cout << "Enter a substring to search for: ";
      cin.ignore(); //Flush previous lines from the buffer
      getline(cin, substrSearch); //We need to include whitespace; cin skips whitespace
      int substrIndex = find(inputString, substrSearch); //Calls the find function and stores the return value

      if (substrIndex != -1) {
        cout << "Substring \""<< substrSearch << "\" found at index: " << substrIndex << endl;
      } else {
        cout << "Substring \"" << substrSearch << "\" not found. " << endl;
      }

    } else { //End of large if-statement
      cout << "Invalid choice. Please try again." << endl;
    }
  }
  return 0;
}