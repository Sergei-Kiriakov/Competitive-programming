//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 998244353, big = 2e6;

vector<vector<int> > g;

int cnt_ig, cnt_piv;
vector<bool> used;
vector<int> piv_ig, piv;

void dfs(int v, int p = -1)
{
    used[v] = true;
    cnt_ig += piv_ig[v];
    cnt_piv += piv[v];
    for (auto u : g[v])
    {
        if (u == v)
            continue;
        if (used[u])
            continue;
        dfs(u, v);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int d = 1; d < 1e9 + 1; d <<= 1)
    {
        int now = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((a[i] & d) == d)
                now = i + 1 - now;
            ans = (ans + (i + 1) * now % mod * d) % mod;
        }
        now = 0;
        for (int i = n - 1; i > -1; --i)
        {
            if ((a[i] & d) == d)
                now = n - i - now;
            ans = (mod + ans - i * now % mod * d) % mod;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
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