#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{

    // Question 1
    string str = "(foo (bar (baz)))";
    regex pattern(R"(\((?:[^()]+)\))");
    smatch matches;

    while (regex_search(str, matches, pattern)) {
        cout << matches[0] << '\n';
        str = matches.suffix().str();
    }

 

    return 0;
}