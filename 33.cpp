#include <iostream>
#include <regex>

using std::cout;
using std::endl;
using std::string;
using std::regex;
using std::smatch;
using std::regex_search;

int main(void)
{
	string str = "random txt john.do_e@example.com rand text";
    //[A-Z a-z 0-9 _\-\.]+[@][a-z]+[\.][a-z]{2,3}
	regex regexp(R"(\S+@\S+)");
	smatch match;

	regex_search(str, match, regexp);

	cout << "Matched emails are:" << endl;

	for (auto x : match)
		cout << x << endl;

	return 0;
}