//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int> > > g(n);
    for (int i = 0; i < m; ++i)
    {
        int v, u, x;
        cin >> v >> u >> x;
        --v; --u;
        g[v].push_back({u, x});
        g[u].push_back({v, x});
    }
    vector<pair<int, int> > ask(k);
    for (int i = 0; i < k; ++i)
    {
        int s, y;
        cin >> s >> y;
        --s;
        ask[i] = {s, y};
        g[0].push_back({s, y});
    }
    vector<int> d(n, 1e18);
    d[0] = 0;
    priority_queue<pair<int, int> > q;
    q.push({0, 0});
    vector<int> cnt(n, 0);
    while (!q.empty())
    {
        int v = q.top().second, x = -q.top().first;
        q.pop();
        if (x > d[v])
            continue;
        for (auto temp : g[v])
        {
            int u = temp.first, ww = temp.second;
            if (d[v] + ww < d[u])
            {
                cnt[u] = 1;
                d[u] = d[v] + ww;
                q.push({-d[u], u});
            }
            else if (d[v] + ww == d[u])
            {
                ++cnt[u];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < k; ++i)
    {
        int u = ask[i].first, ww = ask[i].second;
        if (d[u] < ww)
            ++ans;
        else if (d[u] == ww and cnt[u] > 1)
        {
            ++ans;
            --cnt[u];
        }
    }
    cout << ans << endl;
}

int32_t main()
{
//    ofstream cout("sum.out");
//    ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(9);
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