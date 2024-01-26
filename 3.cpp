#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int main()
{
    string str;
    int i,len=0,n;
    char temp;
    cout<<"Enter your word : "<<endl;
    cin>>str;
    len=str.length();
    n=len-1;
    for(i = 0; i <=(len/2); i++){
        temp=str[i];
        str[i]=str[n];
        str[n]=temp;
        n--;
    }
    for(int i=0;i<str.length();i++){
        cout<<str[i];
    }
    return 0;
}
