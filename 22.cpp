#include <iostream>
#include <fstream>
#include <cstring>

using std::cin;
using std::cout;
using std::fstream;
using std::ios;

class copy
{
	fstream ifile;
	fstream ofile;
	char buff[50];

public:
	copy()
	{
		cout << "Enter input filename: ";
		cin >> buff;
		ifile.open(buff, ios::in);

		cout << "Enter output filename: ";
		cin >> buff;
		ofile.open(buff, ios::out | ios::trunc);
	}

	void run()
	{
		while (!ifile.eof())
		{
			ifile.getline(buff, 51);
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
	copy copy;
	copy.run();

	return 0;
}