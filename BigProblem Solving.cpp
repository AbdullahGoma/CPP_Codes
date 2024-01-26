#include <iostream>
using namespace std;

int Prime(int number) {
int flag=1;
cout << " Enter Number : ";
cin >> number;
for (int i = 2; i < number; i++)
{
if (number % i == 0) {
flag = 0;
break;
}
}
if (flag == 1) {
cout <<endl<< number << " : is Prime Number " << endl;
}
else {
cout <<endl <<number << " : is NOT Prime Number " << endl;
}
return 0;
}

int Perfect(int number) {
int sum = 0 , m;
cout << " Enter Number : ";
cin >> number;
m = number;
for (int i = 1; i < number; i++)
{
if (number % i == 0)
{
sum += i;
}
}
if (sum == m) {
cout <<endl<< number << " : is Perfect Number " << endl;
}
else {
cout <<endl <<number << " : is NOT Perfect Number " << endl;
}
return 0;
}

int Convert(int number) {
int reversing=0, digit, m;
cout << " Enter Number : ";

cin >> number;
cout << " \n";
while (number > 0) {
digit = number % 10;
number /= 10;
reversing = reversing * 10 + digit;
}
while (reversing > 0)
{
m = reversing % 10;
reversing /= 10;
switch (m)
{
case 0:
cout << " Zero ";
break;
case 1:
cout << " One ";
break;
case 2:
cout << " Two ";
break;
case 3:
cout << " There ";
break;
case 4:
cout << " Four ";
break;
case 5:
cout << " Five ";
break;
case 6:
cout << " Six ";
break;
case 7:
cout << " Seven ";
break;
case 8:
cout << " Eight ";
break;
case 9:
cout << " Nine ";
break;
}
}
cout << endl;
return 0;
}

int Even_Odd(int number)
{
cout << " Enter Number : ";
cin >> number;

if (number % 2 == 0)
cout <<endl<< number << " : is Even Number " << endl;
else
cout <<endl<<number << " : is Odd Number " << endl;
return 0;
}

int Factorial(int number) {
int factorial=1;
cout << " Enter Number : ";
cin >> number;
for (int i = 1; i <= number; i++) {
factorial *= i;
}
cout << "\n Factorial Of : " << number << " is : " <<
factorial<<endl;
return 0;
}

int Reversing(int number) {
int digit, reversing=0 , m;
cout << " Enter Number : ";
cin >> number;
m = number;
while (number > 0)
{
digit = number % 10;
number /= 10;
reversing = reversing * 10 + digit;
}
cout << "\n Reversing of " << m << " is " << reversing<<endl;
return 0;
}

int Palindrom(int number) {
int digit, reversing = 0 , m;
cout << " Enter Number : ";
cin >> number;
m = number;
while (number > 0)
{

digit = number % 10;
number /= 10;
reversing = reversing * 10 + digit;
}
if (m == reversing) {
cout <<endl <<m << " : is Palindrom Number " << endl;
}
else
cout <<endl<< m << " : is Not Palindrom Number " << endl;
return 0;
}
int Factors(int number)
{
int factor;
cout << " Enter Number : ";
cin >> number;
cout << " The Factors Of : " << number<<" is \n" ;
for (int i = 1; i < number; i++)
{
if (number % i == 0)
cout << i << " ";
}
cout << endl;
return 0;
}
int main()
{
int prime , number=0 , perfect , option , convert , even_odd ,
factorial , reversing , palindrom , factors;
cout<<"Hello Sir , choose what you want to do from This list "<<endl;
do {
cout<<"1- check if number Primer or not 2- check if number Perfect or not "<<endl;
cout<<"3- Convert Number as Words 4- check if number Even or Odd "<<endl;
cout<<"5- To Find Factorial Of Number "<<endl;
cout<<"6- To Find Reversing of Number "<<endl;
cout<<"7- To Check if Number Palindrom or Not "<<endl;
cout<<"8- To Find Factors of Number "<<endl;
cout<<"9- To Exit from Program "<<endl;
cout<<"Your Option : ";
cin>>option;
cout << " \n \n";
switch (option)
{
case 1:
prime = Prime(number);
break;
case 2:
perfect = Perfect(number);
break;
case 3:

convert = Convert(number);
break;
case 4:
even_odd = Even_Odd(number);
break;
case 5:
factorial = Factorial(number);
break;
case 6:
reversing = Reversing(number);
break;
case 7:
palindrom = Palindrom(number);
break;
case 8:
factors = Factors(number);
}
if (option > 9 || option < 1)
cout << "WRONGING MASSAGE : CHOSE CORRECT OPTION "<<endl;
} while (option != 9);
system("pause");
return 0;
}