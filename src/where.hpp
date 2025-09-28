#include <string>

std::string hello();
int find(const std::string& str, char c, bool caseSensitive = true, int startPos = 0);
int find(const std::string& str, const std::string& substr, bool caseSensitive = true, int startPos = 0);