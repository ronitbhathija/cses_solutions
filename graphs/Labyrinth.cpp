#include <bits/stdc++.h>
using namespace std;
#define int long long

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char mov[] = {'R', 'L', 'U', 'D'};

// this dfs calculates any one path not the shortest one

void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited, string &psf)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '#')
        return;
    if (grid[i][j] == 'B')
    {
        cout << "YES" << endl;
        cout << psf.size() << endl;
        cout << psf << endl;
        exit(0);
    }

    visited[i][j] = true;

    for (int k = 0; k < 4; k++)
    {
        int new_i = i + dx[k];
        int new_j = j + dy[k];

        if (new_i >= 0 && new_j >= 0 && new_i < grid.size() && new_j < grid[0].size() && grid[new_i][new_j] != '#' && !visited[new_i][new_j])
        {
            psf += mov[k];
            dfs(new_i, new_j, grid, visited, psf);
            psf.pop_back();
        }
    }

    visited[i][j] = false;
}

void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    queue<pair<pair<int, int>, string>> q;
    q.push({{i, j}, ""});

    while (!q.empty())
    {
        int i1 = q.front().first.first;
        int j1 = q.front().first.second;
        string temp = q.front().second;

        if (grid[i1][j1] == 'B')
        {
            cout << "YES" << endl;
            cout << temp.size() << endl;
            cout << temp << endl;
            exit(0);
        }

        q.pop();

        if (visited[i1][j1])
            continue;

        visited[i1][j1] = true;

        for (int k = 0; k < 4; k++)
        {
            int new_i = i1 + dx[k];
            int new_j = j1 + dy[k];

            if (new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() && grid[new_i][new_j] != '#' & !visited[new_i][new_j])
            {
                q.push({{new_i, new_j}, temp + mov[k]});
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                bfs(i, j, grid, visited);
            }
        }
    }
    cout << "NO" << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t ;

    while (t--)
    {
        solve();
    }

    return 0;
}