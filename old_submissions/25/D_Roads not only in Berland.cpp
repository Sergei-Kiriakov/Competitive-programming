//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 7, ddl = 179;

vector<bool> used;
vector<vector<int> > g;
vector<vector<int> > path;

void dfs (int v, int p = -1)
{
    used[v] = true;
    if (p != -1)
        path.push_back({p, v});
    for (int u : g[v])
    {
        if (!used[u])
            dfs(u, v);
    }
}

void solve()
{
    int n;
    cin >> n;
    map<vector<int>, int> edges;
    vector<vector<int> > inv(n);
    g = vector<vector<int> > (n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges[{u, v}] = i;
        edges[{v, u}] = i;
        inv[i] = {v, u};
    }
    int ans = n - 1;
    used = vector<bool> (n, false);
    vector<int> need_edges(n, 0);
    vector<int> link_vertex;
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
        {
            path.clear();
            dfs(i);
            ans -= path.size();
            for (auto elem : path)
            {
                need_edges[edges[elem]] = 1;
            }
            link_vertex.push_back(i);
        }
    }
    vector<vector<int> > trash_edges;
    for (int i = 0; i < n - 1; ++i)
        if (need_edges[i] == 0)
            trash_edges.push_back(inv[i]);
    cout << ans << endl;
    for (int i = 1; i < link_vertex.size(); ++i)
    {
        cout << trash_edges[i - 1][0] + 1 << " " << trash_edges[i - 1][1] + 1 << " ";
        cout << link_vertex[i - 1] + 1 << " " << link_vertex[i] + 1 << endl;
    }
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/