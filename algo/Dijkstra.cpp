#include <bits/stdc++.h>

void dijkstra(std::vector<std::vector<std::pair<int, int> > > & g, int start=0) {
    int n = g.size();
    std::vector<int> d(n, 1e18);
    d[0] = 0;
    std::priority_queue<std::pair<int, int> > q;
    q.push({0, 0});
    while (!q.empty())
    {
        int v = q.top().second, x = -q.top().first;
        q.pop();
        if (x > d[v]) continue;
        for (auto temp : g[v])
        {
            int u = temp.first, ww = temp.second;
            if (d[v] + ww < d[u])
            {
                d[u] = d[v] + ww;
                q.push({-d[u], u});
            }
        }
    }
}