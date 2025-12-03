#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }


    vector<long long>dp(x+1,LLONG_MAX);
    
    for(int i=0;i<n;i++) {
        dp[0]=0;
        for(int j=1;j<=x;j++)
        {   
            long long notake = (i > 0 ? dp[j] : LLONG_MAX);
            long long take = LLONG_MAX;

            if (j >= a[i] && dp[j - a[i]] != LLONG_MAX) {
                take = 1 + dp[j - a[i]];   
            }

            dp[j] = min(take, notake);
        }
    }   

    cout << (dp[x] == LLONG_MAX ? -1 : dp[x]);
    
    

    return 0;
}
