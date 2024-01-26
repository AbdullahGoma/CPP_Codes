#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printnumber(int x){
    if(x){
        printnumber(x/10);
        cout << x%10 << endl;
    }
}

int main(){
    int x;

    cout << "Enter a number : " << endl;
    cin >> x;
    printnumber(x);
    
}