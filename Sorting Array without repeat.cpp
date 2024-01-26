#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void afterr(int arr[],int n)
{
    cout << "Elements After :" << endl;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = i; j < n && arr[i] == arr[j]; ++j) {
			cnt++;
		}
        cout << arr[i] << "    ";
		i = i + cnt - 1;
        
	}
}
void sortt(int arr[],int n){
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            if(arr[i] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
int main(){
    int n;
    cout << "Enter n of array :" << endl;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cout << "Enter the " << i << " th element :" << endl;
        cin >> arr[i];
    }
    sortt(arr,n);
    cout << "Elements before : " << endl;
    for(int i = 0;i < n;i++){
        cout << arr[i] << "   ";
    }
    cout << endl;
    afterr(arr,n);
}
