#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    long long n; 
    cin >> n;
    
    vector<long long> arr(n);
    for(long long &x : arr) cin >> x;
    
    sort(arr.begin(), arr.end());
    
    long long curr = 0;
    for(long long x : arr){
        if(x > curr + 1){
            break;
        }
        curr += x;
    }
    
    cout << curr + 1;
    return 0;
}