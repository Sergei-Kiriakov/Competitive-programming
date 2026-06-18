#include <bits/stdc++.h>

#define Please return
#define Accepted 0
#define int long long
#define endl "\n"
#define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod = 1e8;

vector<vector<int> > g;
vector<int> dep, sz;

void dfs (int v, int p = -1)
{
    for (int u : g[v])
    {
        if (u != p)
        {
            dep[u] = dep[v] + 1;
            dfs(u, v);
            sz[v] += sz[u];
        }
    }
}

void init(int n)
{
    g.clear();
    dep.clear();
    sz.clear();
    g.resize(n);
    dep.resize(n, 1);
    sz.resize(n, 1);
}

void solve ()
{
    int n, k;
    cin >> n >> k;
    init(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        ans.push_back(sz[i] - dep[i]);
    }
    sort(ans.rbegin(), ans.rend());
    int anss = 0;
    for (int i = 0; i < n - k; ++i)
    {
        anss += ans[i]; 
    }
    cout << anss << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
}

/*
No brain
*/
