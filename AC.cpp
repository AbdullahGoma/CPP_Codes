#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::fstream;
using std::ios;
using std::remove;
using std::rename;
using std::endl;
using std::string;

class Q3
{
public:
    void solve()
    {
        fstream ifile;
        char ifile_name[20],t[40];
        int line;
        cout<<"Enter input file name: ";
        cin>>ifile_name;
        ifile.open(ifile_name,ios::in);
        if(!ifile)
            cout<<"file not found\n";
        else
        {
            int counter=0;
            fstream temp;
            temp.open("temp.txt",ios::out);
            cout<<"Enter line number you want to delete\n";
            cin>>line;
            while(!ifile.eof())
            {
                ifile.getline(t,45);
                counter++;
                if(counter!=line)
                {
                    temp<<t<<endl;
                }
            }
            cout<<"Done\n";
            ifile.close();
            temp.close();
            remove(ifile_name);
            rename("temp.txt",ifile_name);
        }
    }
};

int main(void)
{
	Q3 solve;
	solve.solve();

	return 0;
}