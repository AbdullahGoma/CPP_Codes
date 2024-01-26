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
	string str = "random txt https://www.ex.com/%user rand text";

	regex regexp(R"(https?:\/\/\w+(\.\w+)*(\/[\w@:%_+.~#?&\/=]+)*)");//\S+

	smatch match;

	regex_search(str, match, regexp);

	cout << "Matched URLs are:" << endl;

	for (auto x : match)
		cout << x << endl;

	return 0;
}