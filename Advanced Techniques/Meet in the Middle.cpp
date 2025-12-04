#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    long long n,x;
    cin>>n>>x;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    vector<vector<long long>>dp(n+1,vector<long long>(x+1,0));

    for(int i=0;i<=n;i++)
        dp[i][0]=1;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=x;j++)
        {
            if(a[i-1]<=j && j-a[i-1]>=0){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    cout<<dp[n][x]<<endl;
    

    return 0;
}
