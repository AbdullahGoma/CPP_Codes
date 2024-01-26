#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printnumberbits(int x){
    if(x){
        printnumberbits(x/2);
        cout << x % 2;
    }
}

int main(){
    int x;

    cout << "Enter a number : " << endl;
    cin >> x;
    printnumberbits(x);
    
}