#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
using namespace std;

int main() {

    int n,m;
    cin>>n>>m;

    vector<vector<int>>edges(m,vector<int>(2));
    vector<int>indegree(n+1,0);
    vector<vector<int>>adj(n+1);

    for(int i = 0; i < m; i++) {
        cin >> edges[i][0]>> edges[i][1];
        indegree[edges[i][1]]++;
        adj[edges[i][0]].push_back(edges[i][1]);
    }


    
    vector<int>topo;
    queue<int>q;
    for(int i=1;i<=n;i++)
        if(indegree[i]==0)
            q.push(i);

    while(!q.empty()) {

        int node=q.front();q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    vector<int>dist(n+1,-1e9),parent(n+1,-1);
    dist[1]=1;

    for(auto u:topo){
        if(dist[u]<0)continue;
        for(auto v:adj[u]){
            if(dist[u]+1>dist[v]){
                dist[v]=dist[u]+1;
                parent[v]=u;
            }
        }
    }
    if(dist[n] < 0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int>ans;
    int curr =n;
    ans.push_back(curr);
    while(curr!=1){
        ans.push_back(curr);
        curr=parent[curr];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto it:ans)
        cout<<it<<" ";
    cout<<endl;

    
    return 0;
}