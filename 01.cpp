#include <iostream>
#include <conio.h>

using namespace std;

void getDate(int *month, int *day, int *year);
int checkDate(int month, int day, int year);
void displayMessage(int status);

int main()
{
    int month, day, year;
    int s = 0;

    getDate(&month, &day, &year);
    do
    {
        checkDate(month, day, year);
        displayMessage(s);
        getDate(&month, &day, &year);
    }
    while (_getch() != EOF);
}

void getDate(int *month, int *day, int *year)
{
    char fill;
    fill = '/';
    cout << "Enter a date in mm/dd/yyyy form: ";
    cin >> *month;
    if (cin.get() != '/')
    {
        cout << "expected /" << endl;
    }
    cin >> *day;
    if (cin.get() != '/')
    {
        cout << "expected /" << endl;
    }
    cin >> *year;
    cout << *month << fill << *day << fill << *year << endl;
};

int checkDate(int month, int day, int year)
{
    if ((month = 1) || (month = 3) || (month = 5) || (month = 7) ||
        (month = 8) || (month = 10) || (month = 12))
    {
        day <= 31;
    }
    else if ((month = 4) || (month = 6) || (month = 9) || (month = 11))
    {
        day <= 30;
    }
    else if ((month = 2) && (year % 4 == 0))
    {
    day <= 29;
    }
    else if ((month = 2) && (year % 4 != 0))
    {
        day <= 28;
    };
    int status = 0;
    if ((year < 999) || (year > 10000))
    {
        status == 1;
    }
    if ((month < 1) || (month > 12))
    {
        status == 2;
    }
    else if ((day < 1) || (day > 31))
    {
        status == 3;
    }
    else if ((day < 1) || (day > 30))
    {
        status == 4;
    }
    else if ((day < 1) || (day > 29))
    {
        status == 5;
    }
    else if ((day < 1) || (day > 28))
    {
        status == 6;
    }
    return status;
};

void displayMessage(int status)
{
    if (status == 0)
    {
        cout << "Good date!" << endl;
    }
    if (status == 1)
    {
        cout << "Bad year" << endl;
    }
    if (status == 2)
    {
        cout << "Bad month" << endl;
    }
    if (status == 3)
    {
        cout << "Bad day. Not 1-31" << endl;
    }
    if (status == 4)
    {
        cout << "Bad day, not 1-30" << endl;
    }
    if (status == 5)
    {
        cout << "Bad day, not 1-29" << endl;
    }
    if (status == 6)
    {
        cout << "Bad day, not 1-28" << endl;
    }
    _getch();
}
