vector<vector<pair<int, int> > > g(n);
vector<int> d(n, 1e18);
d[0] = 0;
priority_queue<pair<int, int> > q;
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
