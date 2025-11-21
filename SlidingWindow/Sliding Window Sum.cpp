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

    long long sum=0;
    for(int i=0;i<k;i++)
        sum+=arr[i];

    long long xorr=sum;
    int l=0,r=k;

    while(r<n) {
        sum+=arr[r];
        sum-=arr[l];
        xorr^=sum;
        l++;r++;
    }

    cout<<xorr<<endl;


    return 0;
}
