#include <iostream>
#include <string>

  using namespace std;

#include "src/where.hpp"

int main() {
  bool run = true; //Controls while loop
  string inputString; //Store user's input string
  int choice = -1; //Start with invalid choice
  cout << "What string would you like to use as your input?" << endl;
  getline(cin, inputString); //Reading user input
  cin.ignore(); //Flush the buffer to cin can prompt user again

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

      cout << "Invalid input. Please try again."
      << "1. Character \n"
      << "2. Substring \n"
      << "3. Exit \n"
      << "Enter your choice: "<< endl;
    } else if (choice == 0) {
      cout << "Bye bye!" << endl;
      run = false; //Kills the while-loop
    } else if (choice == 1) {
      cout << "You chose character search.\n";
      //-------> YOU NEED TO ADD YOUR CHARACTER FUNCTION CALL HERE!!!!! <-------
    } else if (choice == 2) {
      cout << "You chose substring search.\n";
      //-------> YOU NEED TO ADD YOUR SUBSTRING FUNCTION CALL HERE!!!!! <-------
    } else {
      cout << "Invalid choice. Please try again." << endl;
    }
  }
  return 0;
}