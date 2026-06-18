//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 7, big = 2e6;

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
    int n, m;
    cin >> n >> m;
    vector<int> wan(m);
    piv_ig = vector<int> (n, 0);
    for (int i = 0; i < m; ++i)
    {
        cin >> wan[i];
        ++piv_ig[wan[i] - 1];
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int dd;
        cin >> dd;
    }
    int l;
    cin >> l;
    piv = vector<int> (n);
    for (int i = 0; i < l; ++i)
    {
        int dd;
        cin >> dd;
        ++piv[dd - 1];
    }
    int G;
    cin >> G;
    g = vector<vector<int> > (n);
    for (int i = 0; i < G; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    used = vector(n, false);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
        {
            cnt_ig = 0;
            cnt_piv = 0;
            dfs(i);
            ans += min(cnt_piv, cnt_ig);
        }
    }
    int dd = m - ans;
    int ans1 = 0, ans2 = 0;
    ans1 += min(dd, k);
    k -= min(dd, k);
    ans1 += min(ans, k);
    ans2 = ans - min(ans, k);
    cout << ans1 << " " << ans2 << endl;
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