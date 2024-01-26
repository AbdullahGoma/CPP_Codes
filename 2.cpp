#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n,sum=1;
    cout<<"Enter The Number you want factorial to it : "<<endl;
    cin>>n;
    for(int i=1; i<=n;i++){
        sum = sum*i;
    }
    cout<<sum<<"\n";
    return 0;
}
