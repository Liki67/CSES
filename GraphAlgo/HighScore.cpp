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

    
}