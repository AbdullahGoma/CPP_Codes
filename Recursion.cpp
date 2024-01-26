#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void stackTest4()
{
	int dep = 0;
	cout<<dep++<<"\n";
	int arr[100];	// be careful from your created items. E.g. Integrs, Strings, Structs.
	stackTest4();
}

int main(){
    stackTest4();
    return 0;   
}