#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>>edges(m,vector<int>(3));
    for(int i = 0; i < m; i++) 
        cin >> edges[i][0]>> edges[i][1]>>edges[i][2];

    vector<vector<pair<int,int>>>adj(n+1);  
    for(auto it:edges)
        adj[it[0]].push_back({it[1],it[2]});

    vector<long long>distance(n+1,LLONG_MIN);
    vector<long long>visit(n+1,0);

    priority_queue<pair<long long,int>>pq;
    pq.push({0,1});
    distance[1]=0;visit[1]=1;
    bool loop=false;
    while(!pq.empty()) {

        long long edge=pq.top().first;
        int city=pq.top().second;
        pq.pop();
        if (edge != distance[city]) continue;
        for(auto it:adj[city]) {
            if(visit[n]){
                loop=true;
                break;
            }
            if(edge+it.second>distance[it.first] && !visit[it.first]){
                visit[it.first]=1;
                distance[it.first]=edge+it.second;
                pq.push({distance[it.first],it.first});
            }
        }if(loop)break;
    }

    if(loop)
        cout<<-1<<endl;
    else
        cout<<distance[n]<<endl;

    return 0;
}