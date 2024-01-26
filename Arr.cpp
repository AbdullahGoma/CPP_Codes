#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int sum(int arr[],int length,int i){
    if(i == length){
        return 0;
    }else{
        return arr[i] + sum(arr,length,i+1);
    }
}

int main(){
    int n;
    int k = 0;
    cout << "ENter size of array : " << endl;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++){
        arr[i]=1;
    }
    int sumofelemnts = 0;
    for(int i = 0;i < n;i++){
        sumofelemnts +=arr[i];
    }
    cout << "THe sum of elements is : " << sumofelemnts;
}