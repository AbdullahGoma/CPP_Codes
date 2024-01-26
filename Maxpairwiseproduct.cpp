#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long maxpairwiseproductfaster(const vector<int>& numbers){
    int maxIndex = -1;
    int n = numbers.size();
    for(int i = 0;i < n;i++){
        if((maxIndex == -1) || (numbers[i] > numbers[maxIndex]))
            maxIndex = i;
    }
    int secMax = -1;
    for(int i = 0;i < n;i++){
        //(numbers[i] != numbers[maxIndex])
        if(i != maxIndex && ((secMax == -1) || (numbers[i] > numbers[secMax])))
            secMax = i;
    }
    return ((long long)numbers[maxIndex]) * numbers[secMax];
}

long long maxpairwiseproduct(const vector<int>& numbers){
    long long result = 0;
    int n = numbers.size();
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            if(((long long)numbers[i]) * numbers[j] > result){
                result = numbers[i] * numbers[j];
            }
        }
    }
    return result;
}

int main(){
    // while(true){
    //     int n = rand() % 100 + 2;
    //     cout << n << "\n";
    //     vector<int> a;
    //     for(int i = 0;i < n;++i){
    //         a.push_back(rand() % 10000);
    //     }
    //     for(int i = 0;i < n;++i){
    //         cout << a[i] << " ";
    //     }
    //     cout << "\n";
    //     long long res1 = maxpairwiseproduct(a);
    //     long long res2 = maxpairwiseproductfaster(a);
    //     if(res1 != res2){
    //         cout << "Wrong answer : " << res1 << "  " << res2 << "\n";
    //         break;
    //     }else{
    //         cout << "Ok" << "\n";
    //     }
    // }
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(int i = 0;i < n;i++){
        cin >> numbers[i];
    }
    long long result = maxpairwiseproductfaster(numbers);
    cout << result << "\n";
    return 0;
}