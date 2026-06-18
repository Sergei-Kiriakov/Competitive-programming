#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 998244353;

int k;
vector<vector<int> > g, dp;

int dfs (int v, int p = -1)
{
    dp[v][0] = 1;
    int h = 0;
    for (int u : g[v])
    {
        if (u == p) continue;
        int nh = dfs(u, v);
        vector<int> tmp(max(h, nh + 1) + 1);
        for (int i = 0; i < h + 1; ++i)
        {
            for (int j = 0; j < nh + 1; ++j)
            {
                if (i + j + 1 <= k)
                    tmp[max(i, j + 1)] = (tmp[max(i, j + 1)] + dp[v][i] * dp[u][j]) % mod;
                if (i <= k && j <= k)
                    tmp[i] = (tmp[i] + dp[v][i] * dp[u][j]) % mod;
            }
        }
        h = max(h, nh + 1);
        for (int i = 0; i < min(h + 1, k + 1); ++i)
        {
            dp[v][i] = tmp[i];
        }
    }
    return h;
}

void solve()
{
    int n;
    cin >> n >> k;
    g = vector<vector<int> > (n);
    dp = vector<vector<int> > (n, vector<int> (k + 1, 0));
    for (int i = 0; i < n - 1; ++i)
    {
        int v, u;
        cin >> v >> u;
        --v; --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0);
    int ans = 0;
    for (int i = 0; i < k + 1; ++i)
    {
        ans = (ans + dp[0][i]) % mod;
    }
    cout << ans << endl;
}

int32_t main()
{
    // ofstream cout("sum.out");
    // ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    // cin >> tt;
    while(tt-->0)
    {
        solve();
    }  
}


/*
*/  