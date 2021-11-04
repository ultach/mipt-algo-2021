#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
 
std::vector<std::string> getWords(char* s) {
    static const char lastCharInString = '\0';
    static const char delimiter = '.';
 
    std::vector<std::string> words;
    std::size_t i = 0;
 
    while (*s != lastCharInString) {
 
        std::string w = "";
        while (*s != lastCharInString && *s != delimiter) {
            w += *s;
            ++s;
        }
 
        if (w.size()) {
            words.push_back(w);
        }
        ++s;
    }
 
    return words;
}
 
 
void printResult(char* s, std::vector<std::string>& words) {
   static const char lastCharInString = '\0';
   static const char delimiter = '.';
 
   std::size_t i = 0, j = 0;
    
   while (*s != lastCharInString) {
       if (*s == delimiter) {
           std::cout << delimiter;
           ++s;
           continue;
       }
 
       while (*s != lastCharInString && *s != delimiter) {
           ++s;
       }
 
        std::cout << words[j];
        ++j;
   }
}
 
 
 
 
int main() {
 
    std::ios::sync_with_stdio(false);
 
    const int maxSize = 1000000;
    char* s = new char[maxSize];
    scanf("%s", s);
 
 
    std::vector<std::string> words = getWords(s);
    std::sort(words.begin(), words.end());
 
   
    printResult(s, words);
    std::cout << std::endl;
    return 0;
}
 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


std::vector<std::string> getWords(char *s) {
    static const char lastCharInString = '\0';
    static const char delimiter = '.';

    std::vector<std::string> words;
    std::size_t i = 0;

    while (*s != lastCharInString) {

        std::string w = "";
        while (*s != lastCharInString && *s != delimiter) {
            w += *s;
            ++s;
        }

        if (w.size()) {
            words.push_back(w);
        }
        ++s;
    }

    return words;
}


void printResult(char *s, std::vector<std::string> &words) {
    static const char lastCharInString = '\0';
    static const char delimiter = '.';

    std::size_t i = 0, j = 0;

    while (*s != lastCharInString) {
        if (*s == delimiter) {
            std::cout << delimiter;
            ++s;
            continue;
        }

        while (*s != lastCharInString && *s != delimiter) {
            ++s;
        }

        std::cout << words[j];
        ++j;
    }
}


int main() {

    std::ios::sync_with_stdio(false);

    const int maxSize = 1000000;
    char *s = new char[maxSize];
    scanf("%s", s);


    std::vector<std::string> words = getWords(s);
    std::sort(words.begin(), words.end());


    printResult(s, words);
    std::cout << std::endl;
    return 0;
}
 
