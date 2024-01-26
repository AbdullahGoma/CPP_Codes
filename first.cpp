#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter n of array :" << endl;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cout << "Enter n of array :" << endl;
        cin >> a[i];
    }

    int count = 0;
    for(int i = 0;i < n;i++){
        
        if(a[i] % 5 == 0){
            count ++;
        }
    }

    cout << "The number of elements that divides by 5 is equal : " << count << endl;

    return 0;
}