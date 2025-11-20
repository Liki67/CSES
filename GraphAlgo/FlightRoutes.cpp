#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int main(){

    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>edges(m, vector<int>(3));
    for(int i=0;i<m;i++) 
        cin>>edges[i][0] >> edges[i][1] >> edges[i][2];
 
    vector<vector<pair<int,int>>>adj(n+1);
    for(auto it:edges) {
        adj[it[0]].push_back({it[1],it[2]});
    }

    vector<vector<long long>>dist(n+1);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
    pq.push({0,1});

    while(!pq.empty()) {
        long long edge=pq.top().first;
        int city=pq.top().second;
        pq.pop();
        if(dist[city].size()>=(size_t)k)
            continue;

        dist[city].push_back(edge);

        for(auto it:adj[city]) {
            if (dist[it.first].size() < (size_t)k)
                pq.push({edge+it.second,it.first});
            
        }
    }

    for(int i=0;i<k;i++){
        cout<<dist[n][i]<<" ";
    }


    return 0;
}