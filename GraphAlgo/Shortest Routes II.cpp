#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
using namespace std;

int main() {

    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<int>>edges(m,vector<int>(3));
    for(int i = 0; i < m; i++) 
        cin >> edges[i][0]>> edges[i][1]>>edges[i][2];

    vector<vector<int>>queries(q,vector<int>(2));
    for(int i = 0; i < q; i++) 
        cin >> queries[i][0]>> queries[i][1];

    vector<vector<long long>>adj(n+1,vector<long long>(n+1,LLONG_MAX));

    for(int i=1;i<=n;i++) {
        adj[i][i]=0;
    }
    for(auto it:edges){
        adj[it[0]][it[1]]=min(adj[it[0]][it[1]],1LL*it[2]);
        adj[it[1]][it[0]]=min(adj[it[1]][it[0]],1LL*it[2]);
    
    }   

    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            if (adj[i][k] == LLONG_MAX) continue;
            for(int j=1;j<=n;j++) {
                if (adj[k][j] == LLONG_MAX) continue;
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }

    for(auto q:queries) {
        if(adj[q[0]][q[1]]==LLONG_MAX)
            cout<<-1<<endl;
        else
            cout<<adj[q[0]][q[1]]<<endl;
    }
        
    return 0;
}