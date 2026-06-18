#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

//#define int long long
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<vector<int> > > suf(30, vector<vector<int> > (n + 2, {0, 0}));
    vector<vector<vector<int> > > pref(30, vector<vector<int> > (n + 2, {0, 0}));
    for (int i = 0; i < 30; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int bit = !!(a[j] & (1 << i));
            if (j == 0)
            {
                pref[i][j][1] = bit;
                pref[i][j][0] = !bit;
                continue;
            }
            pref[i][j][1] = pref[i][j - 1][!bit] + bit;
            pref[i][j][0] = pref[i][j - 1][bit] + !bit;
        }
        for (int j = n - 1; j > -1; --j)
        {
            int bit = !!(a[j] & (1 << i));
            if (j == n - 1)
            {
                suf[i][j][1] = bit;
                suf[i][j][0] = !bit;
                continue;
            }
            suf[i][j][1] = suf[i][j + 1][!bit] + bit;
            suf[i][j][0] = suf[i][j + 1][bit] + !bit;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int d = __lg(a[i]);
        if (i == 0)
        {
            ans += suf[d][i + 1][1];
            continue;
        }
        if (i == n - 1)
        {
            ans += pref[d][i - 1][1];
            continue;
        }
        ans += (suf[d][i + 1][0] + 1) * 1ll * pref[d][i - 1][1];
        ans += suf[d][i + 1][1] * 1ll * (pref[d][i - 1][0] + 1);
    }
    cout << ans << endl;
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
//    cout << fixed;
//    cout.precision(7);
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