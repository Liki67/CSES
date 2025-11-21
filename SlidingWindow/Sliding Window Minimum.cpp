#include<iostream>
#include<vector>
#include<string>
#include<queue>
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

    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;

    for(int i=0;i<k;i++)
        pq.push({arr[i],i});

    long long xorr=pq.top().first;
    int l=1,r=k;

    while(r<n) {
        pq.push({arr[r],r});
        while(pq.top().second<l)
            pq.pop();
        xorr^=pq.top().first;
        l++;r++;
    }

    cout<<xorr<<endl;

    return 0;
}