#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
float x,c,a,b,error,x1,w,q,r,t;
float func(float); // its the given func
void computation(); //all calculation is here
void line_maker(); //this make line like -----------------
void input_state();
int numOfSteps();
void bisectionMethod();

int main()
{

	input_state();
	line_maker(); 
	cout<< "|\t\tx\t\t  |\tf(x)\t|\t\tInterval\t\t|\n";  //its for table(head)
	line_maker();
	cout<< "|\t\t" << a << "\t\t  |" <<"\t" << func(a)<< "\t|" << "\t\t    -\t     \t\t|\n" ; //first
	line_maker();
	cout << "|\t\t" << b << "\t\t  |" <<"\t" << func(b)<< "\t|" << "\t\t("<<a<<","<<b<<")\t\t\t|" ; //second
	bisectionMethod();
	
	system("pause");
}
float func(float x)
{
	return (w*pow(x,3) + q*pow(x,2) + r*pow(x,1) + t); //given func
}

void input_state()
{
	cout << "\t\t\tWELCOME BISECTION ROOT FINDER PROGRAM\n";
	cout << "please add everything when they ask.\n"; 
	cout << "please enter the 3rd degree polynomial step by step. first enter x^3's coefficient: \n";
	cin >> w;
	cout << "please enter x^2's coefficient: \n";
	cin >> q;
	cout << "please enter x^1's coefficient: \n";
	cin >> r;
	cout << "please enter x^0's coefficient: \n";
	cin >> t;
	cout << "please interval values a and b. first a: \n";
	cin >> a ;
	cout << "second b: \n";
	cin >> b ;
	cout << "please enter error bound: \n";
	cin >> error;
}

int numOfSteps(){
	int n;
	n = ((log1p(b-a-1) - log1p(error-1)) / log1p(1)) + 1;
	return n;
}

void bisectionMethod(){
	int counter = 0;
	int numOfStepss = numOfSteps();
	do
	{ 
		if(func(a)*func(b) < 0){
			//there is a root and do it below code
			x = (a+b)/2; //bisection
			cout << endl;
			line_maker();
			printf("|  (%.6f+%.6f)/2=%.6f |",a,b,x); 
			printf("\t%.3f\t|",func(x));
			if (func(x) > 0) 
			{
				b = x;
			}
			else
			{
				a = x;
			}
            counter++;
			x1 = (a + b) / 2; //bisection for next value

			if(numOfStepss >= counter)
			{
				printf("\t(%.6f,%.6f)\t\t|",a,b);
			}
			else
			{
			cout << "\t\t    -\t     \t\t|\n" ;
			}	
			if(counter == (numOfStepss - 1)){
				// line_maker();
				cout << endl << "\t\t" << x << " is the root." << endl;
			}
		}
	}while ((numOfStepss - 1) > counter);
	// line_maker();
	// if(func(x) > 0){
	// 	cout << endl << "\t\t" << b << " is the root." << endl;
	// }else{
	// 	cout << endl << "\t\t" << a << " is the root." << endl;
	// }
	
}

void computation()
{
	do
	{ 
		if(func(a)*func(b) < 0){
			//there is a root and do it below code
			x = (a+b)/2; //bisection
			cout << endl;
			line_maker();
			printf("|  (%.6f+%.6f)/2=%.6f |",a,b,x); 
			printf("\t%.3f\t|",func(x));

			if (func(a)*func(x) < 0)
			{
				b=x;
			}
			else
			{
				a=x;
			}
			x1 = (a+b)/2; //bisection for next value

			if(fabs(x1-x) > error)
			{
				printf("\t(%.6f,%.6f)\t\t|",a,b);
			}
			else
			{
			cout << "\t\t    -\t     \t\t|\n" ;
			}	
		}
	}
	while (fabs(x1-x) > error);
	line_maker();
	cout<<endl<<"\t\t" << x << " is root"<<endl<<endl;
}

void line_maker()
{
	for(int i=0;i<=88;i++) cout << "-";
	cout << endl;
}
