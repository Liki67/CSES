#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;

void bfs(int node,vector<vector<int>>adj,int n) {
    queue<int>q;vector<int>parent(n+1,-1);vector<int>visit(n+1,0);
    q.push(node);bool found=false;
    visit[node]=1;int cnt=0;
    while(!q.empty()) {
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(!visit[it]){
                q.push(it);
                visit[it]=1;
                parent[it]=node;
                if(it == n){
                    found=true;
                    break;
                }
            }
        }
        if(found)break;
    }
    int end=n,start=1;
    if(visit[n]==0)cout<<"IMPOSSIBLE";
    else{
        vector<int>ans;
        while(end != start) {
            ans.push_back(end);
            end=parent[end];
        }ans.push_back(start);
        reverse(ans.begin(),ans.end());

        cout<<ans.size()<<endl;
        for(auto it:ans){
            cout<<it<<" ";
        }cout<<endl;
    }
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<pair<int,int>>edges(m);
    for(int i = 0; i < m; i++) 
        cin >> edges[i].first >> edges[i].second;

    vector<vector<int>>adj(n+1);
    for(auto [a,b]:edges){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    unordered_set<int>set;
    queue<int>q;
    vector<int>parent(n+1,-1);

    bfs(1,adj,n);


    return 0;
}