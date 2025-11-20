#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;
using namespace std;

vector<vector<int>> adj;
vector<int> visited, parent,rounds;

int startNode = -1, endNode = -1;

bool dfs(int u, int p) {
    visited[u] = 1;

    for (int v : adj[u]) {

        if (!visited[v]) {
            parent[v] = u;
            rounds[v]=rounds[u];
            if (dfs(v, u)) return true;
        }
        else if(visited[v]==1){
            
                startNode = v;
                endNode = u;
                return true;
            }       
        }visited[u]=2;
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    adj.assign(n + 1, {});
    visited.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    rounds.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int cnt=1;
    // try DFS from every component
    for (int i = 1; i <= n; i++) {
        
        if (!visited[i]) {
            rounds[i]=cnt++;
            if (dfs(i, -1))
                break;
        }
    }

    // no cycle found
    if (startNode == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // reconstruct the cycle path
    vector<int> cycle;
    cycle.push_back(startNode);

    for (int v = endNode; v != startNode; v = parent[v])
        cycle.push_back(v);

    cycle.push_back(startNode);

    // output
    cout << cycle.size() << "\n";
    reverse(cycle.begin(),cycle.end());
    for (int x : cycle) cout << x << " ";
    cout << "\n";

    return 0;
}