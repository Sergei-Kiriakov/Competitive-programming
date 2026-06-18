//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93;

vector<int> times, h;
vector<vector<int> > g;
vector<int> val;
int ans = 0;
vector<bool> used;

void dfs(int v, int k, int p = 0)
{
    for (auto u : g[v])
    {
        if (u != p)
        {
            --val[u];
            times[u] = max((h[u] - h[v] + k) % k + times[v], times[u]);
            if (val[u] == 0)
                dfs(u, k, v);
        }
    }
}

void dfs1 (int v, int k, int p = -1)
{
    used[v] = true;
    times[v] += k;
    ans = max(ans, times[v]);
    for (int u : g[v])
    {
        if (!used[u] and times[u] < times[v])
        {
            dfs1(u, k);
        }
    }
}

void init (int n)
{
    h = vector<int> (n, 0);
    val = vector<int> (n, 0);
    g = vector<vector<int> > (n);
    used = vector<bool> (n, false);
    times = vector<int> (n + 1, 0);
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    init(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        ++val[b];
    }
    vector<int> val1 = val;
    for (int i = 0; i < n; ++i)
        if (val1[i] == 0)
        {
            times[i] = h[i];
            dfs(i, k);
        }
    ans = -1e9;
    for (int i = 0; i < n; ++i)
        ans = max(ans, times[i]);
    vector<pair<int, int> > hh;
    for (int i = 0; i < n; ++i)
        hh.push_back({h[i], i});
    sort(all(hh));
    int anss = ans;
    for (int i = 0; i < n; ++i)
    {
        int dd = hh[i].first, ind = hh[i].second;
        anss = min(ans - dd, anss);
        if (val1[ind] == 0)
        {
            dfs1(ind, k);
        }
    }
    cout << anss << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/