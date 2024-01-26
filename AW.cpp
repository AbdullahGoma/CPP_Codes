#include <iostream>
#include<algorithm>
using namespace std;
void soort(int a[],int n)
{
    int temp;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n-1; j++)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }


}
int searchfor(int a[],int n,int key)
{
    for(int i=0; i<n; i++)
    {
        if(key==a[i])
        {
            return i;
            break;
        }
    }
    return -1;

}
int largest(int a[],int n)
{
    int large=a[0];
    for(int i=0; i<n; i++)
    {
        if(a[i]>=a[0])
            large=a[i];
    }
    return large;
}
int smallest(int a[],int n)
{
    int small=a[0];
    for(int i=0; i<n; i++)
    {
        if(a[i]<=a[0])
            small=a[i];
    }
    return small;
}
void check(int a[],int n)
{
    for(int i=0; i<n; i++)
    {
        if(a[i]==1 or a[i]==0)
        {
            cout<<"Array contains 0 or 1\n";
            break;
        }
        else
        {
            cout<<"Array not contains 0 or 1\n";
            break;
        }
    }
}
void rotateE(int a[],int n)
{
    int temp=a[0];
    for(int i=0; i<n; i++)
    {
        a[i]=a[i+1];
    }
    a[n-1]=temp;
}
void max_product(int a[],int n)
{
    int x=a[0];
    int y=a[1];
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[i]*a[j]>x*y)
            {
                x=a[i];
                y=a[j];
            }
        }
    }
    cout<<"The Maximum Product is:"<<x*y<<" of pairs:"<<x<<","<<y<<endl;
}
void max_diff(int a[],int n)
{
    int x=a[0];
    int y=a[1];
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[j]-a[i]>y-x)
            {
                x=a[i];
                y=a[j];
            }
        }
    }
    cout<<"The Maximum difference is:"<<y-x<<" of pairs:"<<x<<","<<y<<endl;
}
int main()
{
    int op=1;
    cout<<"Enter Array Size\n";
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter Array Elements\n";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"----------------------\n";
    while(op!=0)
    {
        cout<<"1-Sort Array\n2-Reverse Array\n3-Search in Array\n4-Find Largest Element\n5-Find Smallest Element\n6-check if array contain 0 and 1\n7-cyclically rotate\n8-Find maximum product\n9-Find maximum difference\n";
        cin>>op;
        switch(op)
        {
        case 1:
            std::sort(a,a+n);
            cout<<"The Sorted Array is\n";
            for(int i=0; i<n; i++)
            {
                cout<<a[i]<<"\t";
            }
            cout<<endl;
            cout<<"----------------------\n";
            break;
        case 2:
            cout<<"The Reversed Array is\n";
            for(int i=n-1; i>=0; i--)
            {
                cout<<a[i]<<"\t";
            }
            cout<<endl;
            cout<<"----------------------\n";
            break;
        case 3:
            cout<<"Enter Key For Search\n";
            int key,x;
            cin>>key;
            x=searchfor(a,n,key);
            if(x!=-1)
                cout<<"Element Found At Position: "<<x+1<<endl;
            else
                cout<<"Element Not Found\n";
            cout<<"----------------------\n";
            break;
        case 4:
        {
            int large=largest(a,n);
            cout<<"The Largest Element is:"<<large<<endl;
            cout<<"----------------------\n";
            break;
        }
        case 5:
        {
            int small=smallest(a,n);
            cout<<"The Largest Element is:"<<small<<endl;
            cout<<"----------------------\n";
            break;
        }
        case 6:
            check(a,n);
            cout<<"----------------------\n";
            break;
        case 7:
            cout<<"The cyclically rotate Array is\n";
            rotateE(a,n);
            for(int i=0; i<n; i++)
            {
                cout<<a[i]<<"\t";
            }
            cout<<endl;
            cout<<"----------------------\n";
            break;
        case 8:
            max_product(a,n);
            cout<<"----------------------\n";
            break;
        case 9:
            max_diff(a,n);


        }


    }
    return 0;
}

