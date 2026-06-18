class LCA
{
protected:
    SparceTable<pair<int, int> > tr;
    vector<pair<int, int> > ans;
    vector<int> tin, tout;
    vector<vector<int> > g;
    int tic, n;

    void dfs(int v = 0, int p = -1, int deep = -1)
    {
        ++deep;
        tin[v] = tic;
        ans.push_back({deep, v});
        ++tic;
        for (int u : g[v])
        {
            if (u == p) continue;
            dfs(u, v, deep);
            ans.push_back({deep, v});
            ++tic;
        }
        tout[v] = tic;
    }
public:
    LCA (vector<vector<int> > g_)
    {
        n = g_.size(); g = g_;
        tin = vector<int> (n, -1);
        tout = vector<int> (n, -1);
        tic = 0; dfs();
        tr = SparceTable<pair<int, int> > (ans);
    }
    int get(int v, int u)
    {
        if (tin[v] < tin[u] and tout[v] > tout[u]) return v;
        if (tin[u] < tin[v] and tout[u] > tout[v]) return u;
        if (u == v) return u;
        if (tout[v] > tin[u]) swap(v, u);
        return tr.get(tout[v], tin[u]).second;
    }
};
