#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<climits>
using namespace std;


void minFlights(vector<vector<pair<int,int>>>& adj, int n) {
    const long long INF = 1e18;
    const int mod = 1e9+7;

    vector<long long> dist(n+1, INF);
    vector<long long> ways(n+1, 0);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

    dist[1] = 0;
    ways[1] = 1;
    pq.push({0,1});
    vector<long long>minNum(n+1,INF);
    vector<long long>maxNum(n+1,-INF);
    minNum[1]=0;
    maxNum[1]=0;

    while(!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if(d != dist[node]) continue;

        for(auto &it : adj[node]) {
            int nxt = it.first;
            long long w = it.second;

            if(dist[node] + w < dist[nxt]) {
                dist[nxt] = dist[node] + w;
                ways[nxt] = ways[node];
                pq.push({dist[nxt], nxt});
                minNum[nxt] = minNum[node]+1;
                maxNum[nxt] = maxNum[node]+1;
            }
            else if(dist[node] + w == dist[nxt]) {
                ways[nxt] = (ways[nxt] + ways[node]) % mod;
        
                minNum[nxt] = min(minNum[nxt],minNum[node]+1);
                
                maxNum[nxt] = max(maxNum[nxt],maxNum[node]+1);
            }
        }
    }
    cout<<dist[n]<<" "<<ways[n]<<" "<<minNum[n]<<" "<<maxNum[n]<<endl;
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>>arr(m);
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[i]={a,b,c};
        adj[a].push_back({b,c});
    }

    
    minFlights(adj,n);
    
    return 0;
}
