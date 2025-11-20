#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
using namespace std;

int n, m;
vector<string> grid;
vector<vector<int>> distA, distM;
vector<vector<pair<int,int>>> parent;
vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

bool isBorder(int x, int y) {
    return (x == 0 || y == 0 || x == n-1 || y == m-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    distA.assign(n, vector<int>(m, 1e9));
    distM.assign(n, vector<int>(m, 1e9));
    parent.assign(n, vector<pair<int,int>>(m, {-1, -1}));

    queue<pair<int,int>> qM, qA;
    int ax, ay;

    // push all monsters (multi-source BFS)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                qM.push({i, j});
                distM[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                ax = i, ay = j;
                qA.push({i, j});
                distA[i][j] = 0;
            }
        }
    }

    // BFS for monsters
    while (!qM.empty()) {
        auto [x, y] = qM.front(); qM.pop();
        for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] == '#' || distM[nx][ny] <= distM[x][y] + 1) continue;
            distM[nx][ny] = distM[x][y] + 1;
            qM.push({nx, ny});
        }
    }

    // BFS for A
    while (!qA.empty()) {
        auto [x, y] = qA.front(); qA.pop();

        // Check escape
        if (isBorder(x, y)) {
            cout << "YES\n";

            string path = "";
            while (grid[x][y] != 'A') {
                auto [px, py] = parent[x][y];
                if (px == x-1 && py == y) path.push_back('D');
                else if (px == x+1 && py == y) path.push_back('U');
                else if (px == x && py == y-1) path.push_back('R');
                else if (px == x && py == y+1) path.push_back('L');
                x = px; y = py;
            }
            cout<<path.size()<<endl;
            reverse(path.begin(), path.end());
            cout << path << "\n";
            return 0;
        }

        for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] == '#') continue;

            if (distA[nx][ny] != 1e9) continue;
            if (distA[x][y] + 1 >= distM[nx][ny]) continue;

            distA[nx][ny] = distA[x][y] + 1;
            parent[nx][ny] = {x, y};
            qA.push({nx, ny});
        }
    }

    cout << "NO\n";
    return 0;
}