#include <iostream>
#include <string>

using namespace std;

std::string hello() {
   return "Hello World!";
}

//Helps tracks case-sensitivity for character comparison
bool charEquals(char a, char b, bool caseSensitive = true) {
   if (caseSensitive) { //This checks if the search should be case-sensitive. If they are the same, it returns true. Otherwise, it returns false.
      return a == b;
   }
   return tolower(a) == tolower(b); //Assuming the user does not care about case-sensitivity I just force each char to lowercase
}

//Helps match substrings to wildcards (this was painful logic to figure out for some reason)
bool matchWild(const string& str, int pos, const string& pattern, bool caseSensitive = true) {
   if (pattern.empty()) { //If pattern is empty we matched successfully
      return true;
   }
   int j = pos; //Current index of the string

   for (int i = 0; i < pattern.size(); i++) { //Loop iterates over each character in the pattern
      if (pattern[i] == '*') { // '*' matches any sequence (including empty)
         if (i + 1 == pattern.size()) { //If * is the last (trailing) character, it always matches the rest of the string
            return true;
         }

         for (int k = j; k <= str.size(); k++) { //Try all possible starting positions for the rest of the pattern
            if (matchWild(str, k, pattern.substr(i + 1), caseSensitive)) //Recursive call saves memory (hopefully)
               return true;
         }
         return false; //No match found
      } else if (pattern[i] == '?') { // '?' matches any single character
         if (j >= str.size()) {
            return false; //String exhausted
         }
         j++; //Move to next character in string
      } else if (pattern[i] == '\\') { //Escape sequence
         if (i + 1 < pattern.size()) {
            if (j >= str.size() || !charEquals(str[j], pattern[i + 1], caseSensitive)) {
               return false; //Mismatch
            }
            j++; //Move to next index in string
            i++; //Skip the escape character
         }
      }
      else { //Normal character; only runs if above statements aren't hit
         if (j >= str.size() || !charEquals(str[j], pattern[i], caseSensitive))
            return false; //Mismatch or string ended
         j++; //Move to next character in string
      }
   }
   return j <= str.size(); //Pattern exhausted, we matched
}

//Note to self -> const string& reads the original without making a copy and does not modify the original
int find(const string& str, char c, bool caseSensitive = true, int startPos = 0) { //Finds character in a string
   if (startPos >= str.size() || str.empty()) { //Handles edge case in case starting position is longer than string length
      return -1;
   }
   for (int i = startPos; i < str.size(); i++) { //Iterate over string from startPos
      if (charEquals(str[i], c, caseSensitive)) {
         return i; //Returning the index where we found out character
      }
   }
   return -1; //Only runs if the if-statement does not return; the character was not found
}

int find(const string& str, const string& pattern, bool caseSensitive = true, int startPos = 0) { //Finds a substring
   if (startPos > str.size() || str.empty()) { //If starting beyond string or empty string input
         return -1;
      }

      for (int i = startPos; i <= str.size(); i++) { //Loop over all valid starting positions
         if (matchWild(str, i, pattern, caseSensitive)) {
            return i; //Found the substring (or wildcard pattern)
         }
      }
      return -1; //Not found
}