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
   return -1; //Only runs if the if-statement does not return; the character was not found
}

int find(const string& str, const string& substr) { //Finds a substring
   for (int i = 0; i <= str.size() - substr.size(); ++i) { //Runs until difference of str and substr is reached. You don't have to check further than the difference since your substr wouldn't exist past the difference.
      int j = 0; //Tracks how far we MATCHED in the substring; i tracks where we are in the main string
      while (j < substr.size() && str[i + j] == substr[j]) {
         j++;
      }
      if (j == substr.size()) {
         return i; //Returning the starting index of the substr
      }
   }
}