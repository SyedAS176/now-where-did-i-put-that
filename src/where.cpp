#include <iostream>
#include <string>

using namespace std;

std::string hello() {
   return "Hello World!";
}

//Note to self -> const string& reads the original without making a copy and does not modify the original
int find(const string& str, char c) { //Finds character in a string
   for (int i = 0; i < str.size(); ++i) {
      if (str[i] == c) {
         return i; //Returning the index where we found out character
      }
   }
   return -1; //Only runs if the if statement does not return; the character was not found
}

int find(const string& str, const std:: string& substr) { //Finds a substring
   //Add code here
}