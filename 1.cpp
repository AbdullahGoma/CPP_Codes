#include <iostream>
#include <fstream>
#include <cstring>

using std::cin;
using std::cout;
using std::fstream;
using std::ios;



class reverseNames
{
	fstream ifile;
	fstream ofile;
	char buff[40];

public:
	reverseNames()
	{
		cout << "Enter input filename : ";
		cin >> buff;
		ifile.open(buff, ios::in);

		cout << "Enter output filename : ";
		cin >> buff;
		ofile.open(buff, ios::out | ios::trunc);
	}

	void run()
	{
		while (!ifile.eof())
		{
			ifile.getline(buff, 41);
			_strrev(buff);
			if (strlen(buff))
			{
				strcat(buff, "\n");
				ofile.write(buff, strlen(buff));
			}
		}
	}
};

int main(void)
{
	reverseNames input;
	input.run();

	return 0;
}