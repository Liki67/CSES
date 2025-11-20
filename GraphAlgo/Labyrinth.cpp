#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char> > grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    vector<vector<int> > vis(n, vector<int>(m, 0));
    vector<vector<pair<int,int> > > parent(n, vector<pair<int,int> >(m, make_pair(-1, -1)));

    int startI = -1, startJ = -1;
    int endI = -1, endJ = -1;

    // Find A & B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == 'A') {
                startI = i;
                startJ = j;
            }

            if (grid[i][j] == 'B') {
                endI = i;
                endJ = j;
            }
        }
    }

    queue<pair<int,int> > q;
    q.push(make_pair(startI, startJ));
    vis[startI][startJ] = 1;

    // Directions: Down, Up, Right, Left
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    char dirChar[4] = {'D', 'U', 'R', 'L'};

    // BFS
    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        if (x == endI && y == endJ)
            break;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                !vis[nx][ny] && grid[nx][ny] != '#') {

                vis[nx][ny] = 1;
                parent[nx][ny] = make_pair(x, y);
                q.push(make_pair(nx, ny));
            }
        }
    }

    // If unreachable
    if (!vis[endI][endJ]) {
        cout << "NO\n";
        return 0;
    }

    // Reconstruct Path
    string path = "";
    int x = endI, y = endJ;

    while (!(x == startI && y == startJ)) {
        int px = parent[x][y].first;
        int py = parent[x][y].second;

        if (px == x - 1 && py == y) path += 'D';
        else if (px == x + 1 && py == y) path += 'U';
        else if (px == x && py == y - 1) path += 'R';
        else if (px == x && py == y + 1) path += 'L';

        x = px;
        y = py;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";

    return 0;
}