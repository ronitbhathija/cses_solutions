#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited)
{
    if (node < 0 || node >= graph.size() || visited[node])
        return;
    visited[node] = true;

    for (auto neigh : graph[node])
    {
        if (!visited[neigh])
        {
            dfs(neigh, graph, visited);
        }
    }
}

void solve()
{
    int cities, roads;
    cin >> cities >> roads;

    int cnt = 0;

    vector<int> answer;

    vector<vector<int>> graph(cities + 1);
    for (int i = 0; i < roads; i++)
    {
        int u;
        int v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(cities + 1, false);

    for (int node = 1; node <= cities; node++)
    {
        if (!visited[node])
        {
            cnt++;
            answer.push_back(node);
            dfs(node, graph, visited);
        }
    }

    cout << cnt - 1 << endl;

    for (int i = 0, j = 1; i < answer.size() && j < answer.size(); i++, j++)
    {
        cout << answer[i] << " " << answer[j] << endl;
    }
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