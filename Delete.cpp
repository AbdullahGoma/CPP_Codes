#include <iostream>
using namespace std;
int main(){
   int n,element,found = 0;
   cout<<"Enter The number of array :"<<endl;
   cin>>n;
   int x[n];
   for(int i=0;i<n;i++){
    cout<<"Enter The "<<i<<"th element :"<<endl;
    cin>>x[i];
   }
   cout<<"Enter The Element You want delete :"<<endl;
   cin>>element;
   for(int i=0;i<n;i++){
    if(x[i]==element){
       for(int j=i;j<(n-1);j++){
        x[j] = x[j+1];
        found++;
        i--;
       }
       n--;
    }
   }
   if(found==0){
    cout<<"Element is not found!"<<endl;
   }else{
        for(int i=0;i<n;i++){
            cout<<"The "<<i<<" th element is : "<<x[i]<<endl;
        }
   }

    return 0;


}
