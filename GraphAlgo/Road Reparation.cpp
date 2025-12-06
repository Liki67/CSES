#include<iostream>
#include<vector>
#include<string>
using namespace std;
using namespace std;

class DisjointSet {
    /* To store the ranks, parents and 
    sizes of different set of vertices */
    
    
public:
vector<int> rank, parent, size;
    // Constructor
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    // Function to find ultimate parent
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    // Function to implement union by rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    // Function to implement union by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// Solution class

int main() {

        int n,m;
        cin>>n>>m;

        
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < m; i++) 
        {
            int u,v,w;
            cin>>u>>v>>w;
            edges.push_back({w, {u, v}});
        
        }
            
        sort(edges.begin(), edges.end());

        
        DisjointSet ds(n);
        
        long long sum = 0;
        
        for (auto it : edges) {
            int wt = it.first; 
            int u = it.second.first; 
            int v = it.second.second;
            
            if (ds.findUPar(u) != ds.findUPar(v)) {
                
                sum += wt;
                ds.unionBySize(u, v);
            }
        }int cnt=0;
        for(int i=1;i<=n;i++) {
            if(ds.parent[i]==i)cnt++;
        }
        if(cnt>1)cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<sum<<endl;
        return 0;
}