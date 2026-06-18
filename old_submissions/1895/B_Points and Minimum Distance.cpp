//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define remin(x, y) x = min(x, y)
#define remax(x, y) x = max(x, y)
#define lowpos(a, x) int(lower_bound(a.begin(), a.end(), x) - a.begin())
#define uppos(a, x) int(upper_bound(a.begin(), a.end(), x) - a.begin())

using namespace std;

constexpr int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int m = 2 * n;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];
    sort(all(a));
//    int ind = 0, max_dif = -1;
//    for (int i = 1; i < m; ++i)
//    {
//        if (a[i] - a[i - 1] > max_dif)
//        {
//            max_dif = a[i] - a[i - 1];
//            ind = i;
//        }
//    }
    vector<vector<int> > ans(n, vector<int> (2, 0));
    for (int i = 0; i < n; ++i)
    {
        ans[i][0] = a[i];
    }
    for (int i = n; i < m; ++i)
    {
        ans[i - n][1] = a[i];
    }
    int anss = 0;
    for (int i = 1; i < n; ++i)
    {
        anss += ans[i][0] - ans[i - 1][0] + ans[i][1] - ans[i - 1][1];
    }
    cout << anss << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
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