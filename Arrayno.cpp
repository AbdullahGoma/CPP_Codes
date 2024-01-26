#include <iostream>
#include <string>
using namespace std;

bool contain(int b[],int a,int size){
    for(int i = 0;i < size;i++){
        if(b[i] == a){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cout << "Enter size" << endl;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int b[n];
    int counter = 0;
    for(int i = 0;i < n;i++){
        if(!contain(b,a[i],i)){
            b[i] = a[i];
            counter++;
        }
    }
    for(int i = 0;i < counter;i++){
        cout << b[i] << "\t";
    }
}