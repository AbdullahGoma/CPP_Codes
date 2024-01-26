#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
 
//ll prefix_sum[100000];
 
void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}
ll GCD(ll a, ll b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
 
ll LCM(ll a, ll b) {
    return a / GCD(a, b) * b;
}
 
bool Prime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
 
bool EvenOddEqual(int a[],int n) {
    int odd = 0;
    int even = 0;
    for(int i = 0;i < n;i++) {
        if(a[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    return odd == even;
}
 
ll FibBetterEff(int n){
    ll a[n];
    a[0] = 0;
    a[1] = 1;
    for(int i = 2;i < n;i++){
        a[i] = a[i-1] + a[i-2];
    }
    return a[n - 1];;
}
 
bool binarySearch(ll a[],int n,int key){
    int start = 0;
    int end = n - 1;
    while(start <= end){
        int finder = end + (start - end) / 2;
        if(key == a[finder]) return true;
        else if(key > a[finder]) start = finder + 1;
        else end = finder - 1;
    }
    return false;
}
 

 
bool isVowel(char c)
{
    c = toupper(c);
    return (c =='A' || c =='E' || c =='I' || c =='O' || c =='U');
}

bool isIn(char c, string b){
    for(int i = 0;i < b.size();i++){
        if(c == b[i]) return false;
    }
    return true;
}

//ll Summition[100000];
int main ()
{
    init();
	
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int counter = 0;
        for(int i = 0;i < n;i++){
            if(s[i] == 'B'){
                counter++;
                i += (k - 1);
            } 
        }
        cout << counter << endl;
    }
    

    return 0;
}

// int a,b;
//     cin >> a >> b;
//     ll sum = 0;
//     if(b > a) swap(a, b);
//     int index = 0;
//     prefix_sum[index] = b;
//     for(b;b <= a;b++){  
//         if(b % 2 == 0) prefix_sum[index+1] = prefix_sum[index] + b;
//         index++;
//     }
//     cout << prefix_sum[index] << endl;
// int count[INT_MAX];
// for (int i = 0; i < n; i++)
// {
//     int x = a[i];
//     count[x]++;
// }


// vector<ll> a(n);
// average = sum / n;

// sort(a.begin(), a.end());
// reverse(a.begin(), a.end());
// sum = 0;


// vector<int> x;


// for(int i = 0;i < n;i++) {
//     cin >> num;
//     x.insert(x.end(),1,num);
// }

// sort(x.begin(), x.end());

// for(int i = 0;i < x.size();i++) {
    
// }


// int n;
// int num,maximum = INT_MIN;
// cin >> n;
// for(int i = 0;i < n;i++){
//     cin >> num;
//     maximum = max(maximum, num);
// }
// cout << maximum << endl;



// int n, a, b, c;
    // cin >> n >> a >> b >> c;
    // int result = 0;
    // for(int i = 0;i < n;i++) {
    //     for(int j = 0;j < n;j++){
    //         for(int k = 0;k < n;k++){
    //             int curlen = i * a + j * b + k * c;
    //             if(curlen == n) result = max(result, i + j + k);
    //         }
    //     }
    // }
    // for(int i = 0;i < n;i++) {
    //     for(int j = 0;j < n;j++){
    //             int curlen = i * a + j * b;
    //             int remlen = n - curlen;
    //             if(remlen < 0 || remlen % c != 0) continue;
    //             int k = remlen / c;
    //             result = max(result, i + j + k);
    //     }
    // }

    //cout << result << endl;