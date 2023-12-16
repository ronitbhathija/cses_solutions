#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector<int> colors(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (colors[i] == -1)
        {
            queue<int> q;
            q.push(i);
            colors[i] = 0;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (auto child : adj[node])
                {
                    if (colors[child] == -1)
                    {
                        colors[child] = !colors[node];
                        q.push(child);
                    }
                    else if (colors[child] == colors[node])
                    {
                        cout << "IMPOSSIBLE" << endl;
                        return;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << colors[i] + 1 << " ";
    }
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