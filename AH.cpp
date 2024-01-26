#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <conio.h>
#include<iomanip>
#include<stdlib.h>
#include<process.h>

using namespace std;
class Student
{
private:

    char buf[35],name[10],phon[12],dep[10];
public:

    void read (fstream & arch)
    {

        cout << "enter name :";
        cin >> name;
        cout << "enter number phone : ";
        cin >> phon;
        cout << "enter department : ";
        cin >> dep;
        strcpy (buf,"");
        strcat(buf,name);
        strcat (buf,"|\n");
        arch.write(buf,strlen(buf));

    }
    void pack (fstream &iofile,fstream &arch )
    {
        read(arch);

        strcpy (buf,"");
        strcat(buf,name);
        strcat (buf,"|");
        strcat (buf,phon);
        strcat (buf,"|");
        strcat (buf,dep);
        strcat (buf,"|");


        while(strlen(buf)<35)


            strcat(buf,"!");
        strcat(buf,"\n");
        iofile.write(buf,strlen(buf));




    }
    void unpack (fstream & iofile )
    {

        char extra[35];
        while(!iofile.eof())
        {
            iofile.getline(name,10,'|');
            iofile.getline(phon,10,'|');
            iofile.getline(dep,10,'|');
            iofile.getline(extra,35,'\n');



            cout << " name : "<<name<<"\nphone number : "<<phon<<"\ndepartment : "<<dep<<endl;



        }
    }

    int arch_search(fstream & archfile,char k[])
    {
        char t[35];

        int i=0;
        while(! archfile.eof())
        {
            archfile.getline(name,10,'|');
            archfile.getline(t,35,'\n');



            if (strcmp(name,k)==0)
            {
                return i;

            }
            i++;
        }
        return -1;
    }

    void unpack2(fstream &iofile,int i)
    {
        char t[35];

        iofile.seekp (i*37,ios::cur);
        iofile.getline(name,10,'|');
        iofile.getline(phon,12,'|');

        iofile.getline(dep,10,'|');
        iofile.getline(t,35,'|');
        cout << "name : "<< name <<"\nphone number : "<<phon <<"\ndepartment : "<<dep<<endl;


    }

};

int main()
{



    int num,index,j,ch;
    fstream iofile,arch;
    char k[10];
    Student s;
    while(true)
    {

        cout << "1:for add student in file\n2:for search (in file student)\neny number to exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "enter number of students : ";
            cin >> num;

            iofile.open("student.txt",ios::out);
            arch.open("index.txt",ios::out);
            for (int i=0; i<num ; i++)
            {
                cout << "student "<<i+1<<'\n';

                s. pack(iofile,arch);

            }
            arch.close();
            iofile.close();
            break;
        }
        case 2:
        {

            cout << "enter name for search:\n";
            cin >> k;
            arch.open("index.txt",ios :: in );
            iofile.open("student.txt",ios::in);

            j=s.arch_search(arch,k);


            if (j==-1)
            {

                cout << "not found .";

            }
            else
            {

                s.unpack2(iofile,j);
            }
            break;
        }
        default:
        {
            exit(0);
        }
        }
    }
}