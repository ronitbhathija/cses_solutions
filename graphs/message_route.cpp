// this bfs works but tle so we use answer creation kind of stuff
//  void bfs(int start, int end, vector<vector<int>> &graph)
//  {
//      queue<pair<int, vector<int>>> q;

//     q.push({start, {start}});
//     vector<bool> visited(end + 1, false);
//     while (!q.empty())
//     {
//         int node = q.front().first;
//         vector<int> psf = q.front().second;

//         q.pop();
//         if (visited[node])
//             continue;
//         visited[node] = true;

//         if (node == end)
//         {
//             cout << psf.size() << endl;
//             for (auto x : psf)
//             {
//                 cout << x << " ";
//             }

//             exit(0);
//         }

//         for (auto neigh : graph[node])
//         {
//             if (!visited[neigh])
//             {
//                 vector<int> newpsf = psf;
//                 newpsf.push_back(neigh);
//                 q.push({neigh, newpsf});
//             }
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> prev(n + 1, -1);
    queue<int> q;

    q.push(1);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (visited[node])
            continue;
        visited[node] = true;

        for (auto neigh : graph[node])
        {
            if (!visited[neigh] && prev[neigh] == -1)
            {
                prev[neigh] = node;
            }

            if (!visited[neigh])
            {
                q.push(neigh);
            }
        }
    }

    if (!visited[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> result;

    int curr = n;

    while (curr != 1)
    {
        result.push_back(curr);
        curr = prev[curr];
    }

    result.push_back(curr);
    cout << result.size() << endl;
    reverse(result.begin(), result.end());

    for (auto x : result)
        cout << x << " ";
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