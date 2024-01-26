#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;
struct poly
{
    int pow ;
    float cof ;


};
void insertt (poly fx[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout << "enter power\n ";
        cin >> fx[i].pow;
        cout << "enter cof\n";
        cin >> fx[i].cof;

    }
}
void print (poly fx[],int n)
{

    for (int i = 0;i < n;i++)
    {
    if (fx[i].cof != 0){
        if (fx[i].pow != 1 && fx[i].pow != 0){
            cout << fx[i].cof << "X^" << fx[i].pow;
            if (i != n-1)
            cout << " + ";
        }
        else if (fx[i].pow == 1)
        {
            cout << fx[i].cof << "X";
            if (i != n-1)
            cout << " + ";
        }
        else if (fx[i].pow == 0)
        {
        cout << fx[i].cof;
            if(i != n-1)
            cout << " + ";
        }

        }

    }
    cout << endl;
}
void add(poly fx1[],poly fx2[],poly fx3[],int n1,int n2,int &k)
{
    int i=0,j=0;
    k=0;
    while (i<n1&&i<n2)
    {
        if (fx1[i].pow==fx2[j].pow)
        {
            fx3[i].cof=fx1[i].cof+fx2[j].cof;
            fx3[k].pow=fx1[i].pow;
            i++;
            j++;
            k++;

        }
        else if (fx1[i].pow>fx2[j].pow)
        {

            fx3[k]=fx2[j];
            j++;
            k++;
        }
        else if (fx1[i].pow<fx2[j].pow)
        {
            fx3[k]=fx1[i];
            i++;
            k++;
        }
    }
    while (i<n1)
    {
        fx3[k]=fx1[i];
        i++;
        k++;


    }
    while (j<n2)
    {
    fx3[k]=fx2[j];
    k++;
    j++;
    }
}
void df (poly fx[],poly f_x[],int &ndf,int n)
{
    ndf = 0;
    for (int i = 0;i < n;i++)
    {
        if (fx[i].pow!=0 )
        {
            f_x[i].cof =fx[i].pow*fx[i].cof;
            f_x[i].pow =fx[i].pow-1;
            ndf++;
        }
        else {
        f_x[i].cof =0;
            f_x[i].pow =0;
            ndf++;
        }
    }
}
void intg(poly fx[],int n,poly ifx[])
{
    for(int i = 0;i < n;i++)
    {
        ifx[i].pow = fx[i].pow + 1;
        ifx[i].cof = (fx[i].cof) / (fx[i].pow + 1);
    }
}

float cal (poly fx[],int n,float p)
{
    float s=0;
    for (int i=0;i<n;i++)
    {
        s+=(fx[i].cof*(pow(p,fx[i].pow)));
    }
    return s;
}

void add_mul(poly fx1[],poly fx2[],int n1,int n2,int &k)
{
    k=0;
    int arr[1000] = {0};
    for (int i=0;i<n1*n2;i++)
    {
    bool chk = false;
    for (int j=1;j<n1*n2;j++)
    {
        if (fx1[i].pow==fx1[j].pow && arr[fx1[i].pow]==0 && i!=j)
        {
            fx2[k].cof=fx1[i].cof+fx1[j].cof;
            fx2[k].pow=fx1[i].pow;
            k++;
            arr[fx1[i].pow] = 1;
            chk = true;
        }
    }
    if(!chk && arr[fx1[i].pow]== 0){
        fx2[k]=fx1[i];
        k++;
        arr[fx1[i].pow] = 1;
    }
    }
}

void mul(poly fx1[],poly fx2[],poly fx3[],int n1,int n2,int& n3)
{
    int t=0;
    poly fx[n1*n2];
    for (int i=0;i<n1;i++)
    {
        for (int j=0;j<n2;j++)
        {
            fx[t].cof=fx1[i].cof*fx2[j].cof;
            fx[t].pow=fx1[i].pow+fx2[j].pow;
            t++;
        }
    }

    add_mul(fx,fx3,n1,n2,n3);
}
int main ()
{
   int k;
    while (true){
   cout << "**************************\n";
   cout << "* 1:add tow polynomial.  *\n";
   cout << "* 2:deff.                *\n";
   cout << "* 3:Integral.            *\n";
   cout << "* 4:calcolait in point.  *\n";
   cout << "* 5:product.             *\n";
   cout << "* 0:exit                 *\n";
   cout << "**************************\n";
   cin >> k;
   if (k==0)
   break;
   switch(k)
   {

        case 1:
        {
        int n1,n2,c=0;
            cout << "enter number of termes for frist polynomial:\n";
            cin >> n1;
            poly fx1[n1];
            insertt(fx1,n1);
            cout << "enter number of termes for sconde polynomial:\n";
            cin >> n2;
            poly fx2 [n2],fx3[n1+n2];
            insertt(fx2,n2);
            add(fx1,fx2,fx3,n1,n2,c);
            print(fx3,c) ;
            break;

        }
        case 2:
        {
            int n;
            cout << "enter number of termes for the polynomial:\n";
            cin >> n;
            int ndf=n;
            poly fx[n],f_x[ndf];
            insertt(fx,n);
            df(fx,f_x,ndf,n);
            print (f_x,ndf);
            break;
        }
        case 3:
        {
            int n;
            cout << "enter number of termes for the polynomial:\n";
            cin >> n;
            poly fx[n] , ifx[n];
            insertt(fx,n);
            intg(fx,n,ifx);
            print (ifx,n);
            cout << " + c\n";
            break;
        }
        case 4:
        {

         int n,p;
        cout << "enter number of termes for the polynomial:\n";
        cin >> n;

        poly fx[n];
        insertt(fx,n);
        cout << "enter point :";
        cin >> p;
        cout <<"the value is "<< cal(fx,n,p)<<endl;
        break;
        }
        case 5 :
        {
        int n1,n2,n3=0;
        cout << "enter number of termes for frist polynomial:\n";
        cin >> n1;
        poly fx1[n1];
        insertt(fx1,n1);
        cout << "enter number of termes for sconde polynomial:\n";
        cin >> n2;
        poly fx2 [n2],fx3[n1*n2];
        insertt(fx2,n2);
        mul(fx1,fx2,fx3,n1,n2,n3);
        print (fx3,n3);
        break;


        }
   }
}
cout << "thank you for using the program\n";
}