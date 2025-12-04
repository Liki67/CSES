#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int cycle_len_from_start(const vector<int>& adj, int start) {
    unordered_map<int,int> pos;
    int cur = start;
    int step = 0;
    while (true) {
        if (pos.find(cur) != pos.end()) {
            
            if (cur == start) return step - pos[cur];
            else return 0; 
        }
        pos[cur] = step++;
        cur = adj[cur];
        if (cur < 0 || cur >= (int)adj.size()) return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> adj(n);
    for (int i = 0; i < n; ++i) {
        cin >> adj[i];
        --adj[i]; 
    }
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1];
        --queries[i][0];
        queries[i][1];
    }

    vector<int> loopLen(n);
    for (int i = 0; i < n; ++i) {
        loopLen[i] = cycle_len_from_start(adj, i);
    }

    for(int i=0;i<q;i++) {
        int k=queries[i][1];
        int node=queries[i][0];
        
        while(k > 0 && loopLen[node] == 0){
            node = adj[node];
            k--;
        }

        if(k == 0){
            cout << node+1 << "\n";
            continue;
        }

        k %= loopLen[node];
        while(k--){
            node = adj[node];
        }

        cout << node+1 << "\n";
    }
    
    return 0;
}