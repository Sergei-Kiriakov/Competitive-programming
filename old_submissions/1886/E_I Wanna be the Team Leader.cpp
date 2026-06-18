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
    int n, m;
    cin >> n >> m;
    vector<int> b(m);
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(all(a));
    vector<vector<int> > mn(m, vector<int> (n + 10, 1e18));
    for (int i = 0; i < m; ++i)
    {
        for (int l = 0; l < n; ++l)
        {
            int r = l + (b[i] + a[l].first - 1) / a[l].first;
            if (r <= n) mn[i][l] = r;
        }
        for (int l = n - 1; l > -1; --l)
        {
            mn[i][l] = min(mn[i][l], mn[i][l + 1]);
        }
    }
    vector<int> dp(1 << m, 1e18);
    vector<int> p(1 << m, -1);
    dp[0] = 0;
    for (int mask = 0; mask < (1 << m); ++mask)
    {
        if (dp[mask] == 1e18) continue;
        for (int i = 0; i < m; ++i)
        {
            int d = (1 << i);
            if (mask & d) continue;
            int mask2 = mask | d;
            if (dp[mask2] > mn[i][dp[mask]])
            {
                dp[mask2] = mn[i][dp[mask]];
                p[mask2] = mask;
            }
        }
    }
    int mask = (1 << m) - 1;
    if (dp[mask] == 1e18)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<vector<int> > ans(m);
    for (int i = 0; i < m; ++i)
    {
        int d = __lg(mask ^ p[mask]);
        int cnt = 0;
        for (int j = dp[mask] - 1; j > -1; --j)
        {
            ans[d].push_back(a[j].second);
            ++cnt;
            if (cnt * a[j].first >= b[d]) break;
        }
        mask = p[mask];
    }
    for (int i = 0; i < m; ++i)
    {
        cout << ans[i].size() << " ";
        for (int elem : ans[i])
        {
            cout << elem + 1 << " ";
        }
        cout << endl;
    }
}

int32_t main()
{
//    ofstream cout("lca.out");
//    ifstream cin("lca.in");
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