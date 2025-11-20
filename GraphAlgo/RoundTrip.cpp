#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;
using namespace std;

vector<vector<int>> adj;
vector<int> visited, parent;

int startNode = -1, endNode = -1;

bool dfs(int u, int p) {
    visited[u] = 1;

    for (int v : adj[u]) {
        if (v == p) continue; // skip the parent

        if (!visited[v]) {
            parent[v] = u;
            if (dfs(v, u)) return true;
        }
        else {
            // found a back-edge (cycle)
            startNode = v;
            endNode = u;
            return true;
        }
    }
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

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // try DFS from every component
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
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
    for (int x : cycle) cout << x << " ";
    cout << "\n";

    return 0;
}