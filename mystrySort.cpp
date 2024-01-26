#include <iostream>
#include <string>
using namespace std;

void swap(int x,int y){
    int temp = x;
    x = y;
    y = temp;
}

void mystrySort(int a[]){
    int currInd = 0;
    for(int pos = 1;pos < a.length();pos++){
        currInd = pos;
        while(currInd > 0 && a[currInd] < a[currInd - 1]){
            swap(currInd,currInd - 1);
            currInd = currInd - 1;
        }
    }
}

int main(){
    int n;
    cout << "Enter length of array : " << endl;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cout << "Enter the " << i << "th element :" << endl;
        cin >> a[i];
    }
    mystrySort(a);
    for(int i = 0;i < n;i++){
        cout << a[i] << "    ";
    }
    return 0;
}

