#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    
    int n;
    cin>>n;

    vector<long long> arr(n),tower;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        auto it= upper_bound(tower.begin(),tower.end(),arr[i]);
        if(it==tower.end()){
            tower.push_back(arr[i]);
        }else{
            *it=arr[i];
        }
    }
    cout<<tower.size();


    return 0;
}
