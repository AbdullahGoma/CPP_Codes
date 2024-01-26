#include <iostream>
#include <string>
#include <cmath>
#include<bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::out_of_range;

int stringtoNum(string text){
    int sum = 0;
    int powerlevel = 0;
    for(int i = 0;i <= text.length()-1;i++){
        char c = text.at(i);
        int end = (int)c;
        int start = ((int)'A')-1;
        sum += pow(26,powerlevel) * (end - start);
        powerlevel++;
    }
    return sum;
}

int main(){
    string text;
    cout << "Enter string" << endl;
    cin >> text;
    cout << "The number is : " << stringtoNum(text);

    return 0;
}
