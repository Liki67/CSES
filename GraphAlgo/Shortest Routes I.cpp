#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
using namespace std;

int main() {

    int n,m;
    cin>>n>>m;

    vector<vector<int>>edges(m,vector<int>(3));
    for(int i = 0; i < m; i++) 
        cin >> edges[i][0]>> edges[i][1]>>edges[i][2];

    vector<vector<pair<int,int>>>adj(n+1);
    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];
        adj[u].push_back({v, w});
    }   

    vector<long long>distance(n+1,LLONG_MAX);
    distance[1]=0;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
    pq.push({0,1});
    while(!pq.empty()) {
        long long edge=pq.top().first;
        int city=pq.top().second;
        pq.pop();
        if (edge != distance[city]) continue;
        for(auto it:adj[city]) {
            if(edge+it.second<distance[it.first]){
                distance[it.first]=edge+it.second;
                pq.push({distance[it.first],it.first});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<distance[i]<<" ";
    }

    return 0;
}