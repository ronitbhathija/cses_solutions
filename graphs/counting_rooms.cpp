#include <bits/stdc++.h>
using namespace std;
#define int long long

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    if (!(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && !visited[i][j] && grid[i][j] == '.'))
        return;

    visited[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int new_i = i + dx[k];
        int new_j = j + dy[k];

        dfs(new_i, new_j, grid, visited);
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

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                dfs(i, j, grid, visited);
                ans++;
            }
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}