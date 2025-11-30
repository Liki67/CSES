#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
void solve(){
    int n;
    cin>>n;
}
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>>arr(m);
    for(int i=0;i<m;i++) {
        cin>>arr[i].first>>arr[i].second;
    }

    vector<vector<int>>adj(n+1);
    vector<int>indegree(n+1,0);
    for(int i=0;i<m;i++) {
        adj[arr[i].first].push_back(arr[i].second);
        indegree[arr[i].second]++;
    }
        
    queue<int>q;
    for(int i=1;i<=n;i++)
        if(indegree[i]==0)
            q.push(i);

    vector<int>ways(n+1,0);
    ways[1] = 1;

    int mod=1e9+7;
    while(!q.empty()) {
        int node=q.front();q.pop();
        for(auto it:adj[node]){
            indegree[it]--;
            ways[it]=(ways[it]+ways[node])%mod;
            if(indegree[it]==0)
                q.push(it);
        }
    }

    cout<<ways[n]<<endl;



    return 0;
}
