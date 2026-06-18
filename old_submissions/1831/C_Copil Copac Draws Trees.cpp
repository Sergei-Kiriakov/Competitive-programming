#include <bits/stdc++.h>

#define int long long
//#define endl "\n"

using namespace std;

const int mod = 998244353;

map<pair<int, int>, int> c;
vector<vector<int> > g;
int ans;

void dfs (int v, int p = -1, int deep = 1)
{
    for (int u : g[v])
    {
        if (u != p)
        {
            int dop = 0;
            if (p != -1 && c[{v, u}] < c[{v, p}])
                ++dop;
            dfs(u, v, deep + dop);
        }
    }
    ans = max(deep, ans);
}

void solve()
{
    ans = 1;
    int n;
    cin >> n;
    int ind = 0;
    g = vector<vector<int> > (n);
    c.clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int v, u;
        cin >> v >> u;
        --v; --u;
        c[{v, u}] = ind;
        c[{u, v}] = ind;
        g[v].push_back(u);
        g[u].push_back(v);
        ++ind;
    }
    dfs(0);
    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // cout << fixed;
    // cout.precision(15);
    int tt = 1;
    cin >> tt;
    while (tt-->0)
    {
        solve();
    }
}


/*
*/