#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

int helper(int n,int x,vector<int>&a)
{
    if(x==0)
    {
        return 1;
    }
    if(n<0){
        return 0;
    }
    int take=0;
    int notake=0;
    if(x>=a[n])
    {
        take=helper(n,x-a[n],a);
    }
    notake=helper(n-1,x,a);
    return take+notake;
}
int main(int argc, char const *argv[])
{
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<helper(n-1,x,a);
    return 0;
}