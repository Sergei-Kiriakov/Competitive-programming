#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod = 1e9 + 7, d = 179;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> a[i];
    }
    vector<int> ans(n, -1);
    set<int> s;
    int last = n - 1;
    for (int i = 0; i < m; ++i)
    {
        if (s.count(a[i]) == 0)
        {
            s.insert(a[i]);
            if (last > -1)
                ans[last] = i + 1;
            --last;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}

/*
...
*/