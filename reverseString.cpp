#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

string reverseString(string word){
    string empty = "";
    // for(int i = 0;i < word.length();i++){
    //     empty = word[i] + empty;
    // }
    int i = 0;
    while (i < word.length()){
        empty = word[i] + empty;
        i += 1;
    }
    return empty;
}

int main(){
    string word;
    cout << "Enter any string : " << endl;
    cin >> word;
    string temp = reverseString(word);
    cout << "The word after reversing is " << temp << endl;
    if (word == temp)
    {
        cout << "Palandrom." << endl;
    }else
    {
        cout << "Not palandrom." << endl;
    }

}
