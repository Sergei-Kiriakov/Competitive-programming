template<typename T = int>
class HLD
{
protected:
    int n, tic;
    vector<vector<int> > g;
    vector<int> sz, fa, hv, dep, top, tin;
    vector<T> cur, fen;

    void dfs1 (int v, int f)
    {
        sz[v] = 1; fa[v] = f; hv[v] = -1;
        int mx = 0;
        for (int u : g[v])
        {
            if (u == f) continue;
            dep[u] = dep[v] + 1;
            dfs1(u, v);
            sz[v] += sz[u];
            if (sz[u] > mx) { mx = sz[u]; hv[v] = u; }
        }
    }
    void dfs2 (int v, int h)
    {
        top[v] = h; tin[v] = tic++;
        if (hv[v] != -1) dfs2(hv[v], h);
        for (int u : g[v])
        {
            if (u == fa[v] || u == hv[v]) continue;
            dfs2(u, u);
        }
    }
    void fadd (int i, T x) { for (++i; i <= n; i += i & -i) fen[i] += x; }
    T fsum (int i) { T r = 0; for (++i; i > 0; i -= i & -i) r += fen[i]; return r; }
    T fseg (int l, int r) { return fsum(r) - fsum(l - 1); }
public:
    HLD (vector<vector<int> > g_, vector<T> val)
    {
        n = g_.size(); g = g_; tic = 0;
        sz = fa = hv = dep = top = tin = vector<int> (n, 0);
        cur = vector<T> (n, 0);
        fen = vector<T> (n + 1, 0);
        dfs1(0, -1);
        dfs2(0, 0);
        for (int v = 0; v < n; ++v) update(v, val[v]);
    }
    void update (int v, T x)
    {
        fadd(tin[v], x - cur[v]);
        cur[v] = x;
    }
    T query (int u, int v)
    {
        T res = 0;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            res += fseg(tin[top[u]], tin[u]);
            u = fa[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        res += fseg(tin[u], tin[v]);
        return res;
    }
    T subtree (int v) { return fseg(tin[v], tin[v] + sz[v] - 1); }
};
