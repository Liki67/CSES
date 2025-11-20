#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>>edges(m, vector<int>(2));
    vector<int>indegree(n+1,0);
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++) {
        cin>>edges[i][0] >> edges[i][1];
        indegree[edges[i][1]]++;
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    queue<int>q;
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)
            q.push(i);
    }

    while(!q.empty()){
        int node=q.front();q.pop();
        ans.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]!=0){
            cout<<"IMPOSSIBLE"<<endl;return 0;
        }
            

    }
    for(auto it:ans)
        cout<<it<<" ";
    cout<<endl;
 



    return 0;
}