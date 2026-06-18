#include <bits/stdc++.h>

#define Please return
#define Accepted 0
// #define int long long
#define endl "\n"
// #define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod1 = 1e9 + 9, mod2 = 1e9 + 7;

vector<vector<int> > g;
set<int> need_a, need_b;

int ans = 0, dip_a = 0, dip_b = 0;

void dfs (int &dip_a, int &dip_b, int &ans, int d, int v, int dip = 0, int p = -1)
{
    if (need_a.count(v))
    {
        ans += dip - dip_a;
        dip_a = dip;
        if (dip_a - dip_b > d)
        {
            ans += dip_a - dip_b - d;
            dip_b = dip_a - d;
        }
    }
    if (need_b.count(v))
    {
        ans += dip - dip_b;
        dip_b = dip;
        if (dip_b - dip_a > d)
        {
            ans += dip_b - dip_a - d;
            dip_a = dip_b - d;
        }
    }
    for (int u : g[v])
    {
        if (u != p)
        {
            dfs(dip_a, dip_b, ans, d, u, dip + 1, v);
        }
    }
    if (dip != 0 && dip_b >= dip)
    {
        dip_b--;
        ans++;
    }
    if (dip != 0 && dip_a >= dip)
    {
        dip_a--;
        ans++;
    }
}

void solve ()
{
    int n, d;
    cin >> n >> d;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int v, u;
        cin >> v >> u;
        --v; --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int n1;
    cin >> n1;
    for (int i = 0; i < n1; ++i)
    {
        int temp;
        cin >> temp;
        need_a.insert(temp - 1);
    }
    int n2;
    cin >> n2;
    for (int i = 0; i < n2; ++i)
    {
        int temp;
        cin >> temp;
        need_b.insert(temp - 1);
    }
    int dip_a = 0, dip_b = 0, ans = 0;
    dfs(dip_a, dip_b, ans, d, 0);
    cout << ans << endl;
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
