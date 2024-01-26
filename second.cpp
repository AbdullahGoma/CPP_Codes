#include <iostream>
#include <cmath>
using namespace std;

int maximum(int x,int y){
    if(x > y){
        return x;
    }
    return y;
}

int longest_consecutive(int a[],int n){
    int longest_consecutive = 0;
    int counter = 0;
    for(int i = 0;i < n;i++){
        if(a[i] * a[i+1] < 0 ){
            counter++;  
            longest_consecutive = counter;
        }

        if(a[i] * a[i+1] > 0){
            longest_consecutive = maximum(longest_consecutive , counter);
            counter = 0;
        }
    }
    return longest_consecutive;
}
int main(){
    int n;
    cout << "Enter n of array :" << endl;
    cin >> n;
    int a[n];
    cout << "Enter the array :" << endl;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    
    int longest = longest_consecutive(a,n);

    cout << "The longest consecutive is : " << longest << endl;

    return 0;
}