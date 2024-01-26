#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int stringtoint(string text){
    int sum = 0;
    
    for(int i = 0;i <= text.length()-1;i++){
        char c;
        c = text[i];
        sum = sum * 10 + ((int)c - (int)'0');
    }
    return sum;
}

int main(){
    string text;
    cout << "Enter string number to convert it to an integer number :" << endl;
    cin >> text;
    cout << "The number is : " << stringtoint(text);

    return 0;
}
