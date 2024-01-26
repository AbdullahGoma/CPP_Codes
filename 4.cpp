#include <iostream>
using namespace std;
int main()
{
    bool found = false;
    int n,x[5],start,finish,key,Z;
    cout<<"Enter n of sorted Array"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i<<" th index :"<<endl;
        cin>>x[i];
    }
    cout<<"Enter an Element you search it in array :"<<endl;
    cin>>key;
    start = 0;
    finish = n-1;

    while((start<=finish)and(!found)){
        Z = (start + finish)/2;
        if (key == x[Z]){
            found = true;
        }
        else if(key<x[Z]){
            finish = Z-1;
        }else{
        start = Z+1;
        }
    }
    if(found==true){cout<<"The index of element is :"<<Z<<endl;}else cout<<"We didn't find the key";

    return 0;
}

