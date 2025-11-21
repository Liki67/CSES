#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n>>k;

    int x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<long long>arr(n);

    arr[0]=x;
    for(int i=1;i<n;i++) {
        arr[i]=(arr[i-1]*a+b)%c;
    }

    long long orr=arr[0];

    for(int i=1;i<k;i++)
        orr|=arr[i];

    long long ans=orr;
    int l=0,r=k;

    while(r<n) {

        orr|=~(arr[l]);
        orr|=arr[r];
        ans|=orr;
        l++;r++;

    }
    cout<<ans;

    return 0;
}