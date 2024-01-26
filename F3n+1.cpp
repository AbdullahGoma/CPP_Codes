#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int F3n_1(int a){
    if(a == 1){
        return 1;
    }
    if(a % 2 == 0){
        return 1 + F3n_1(a/2);
    }
    return 1 + F3n_1(3 * a + 1);
}

int main(){
    int x;
    cout << "Enter a number you want to know number of sequences from series 3n+1 : " << endl;
    cin >> x;
    cout << "Number of sequances is : " << F3n_1(x) << endl;
}