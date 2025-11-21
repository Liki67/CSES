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

    long long xorr=arr[0];

    for(int i=1;i<k;i++)
        xorr^=arr[i];

    long long ans=xorr;
    int l=0,r=k;

    while(r<n) {

        xorr^=arr[l];
        xorr^=arr[r];
        ans^=xorr;
        l++;r++;

    }
    cout<<ans;

    return 0;
}