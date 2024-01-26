#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int factorial(int a){
    
    if(a <= 1){
        return 1;
    }
    return a * factorial(a-1);
}

int main(){
    int x;
    cout << "Enter a number you want know it factorial : " << endl;
    cin >> x;
    cout << "The factorial of number you entered is : " << factorial(x) << endl;
}

.....................
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int factorial1(int a){
    return a;
}

int factorial2(int a){
    return a * factorial1(a-1);
}

int factorial3(int a){
    return a * factorial2(a-1);
}

int factorial4(int a){
    return a * factorial3(a-1);
}

int main(){
    int x;
    cout << "Enter a number you want know it factorial : " << endl; //enter only four
    cin >> x;
    cout << "The factorial of number you entered is : " << factorial4(x) << endl;
}