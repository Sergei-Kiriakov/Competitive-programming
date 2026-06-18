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
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> b = {a[0]};
    vector<int> c = {1};
    for (int i = 1; i < n; ++i)
    {
        if (a[i] != b.back())
        {
            b.push_back(a[i]);
            c.push_back(1);
        }
        else
        {
            ++c.back();
        }
    }
    bool anss = false;
    for (int i = 0; i < b.size(); ++i)
    {
        if (c[i] == 1 and b[0] == b[i])
        {
            anss = true;
        }
    }
    if (anss and n != 1)
    {
        cout << 1 << endl;
        return;
    }
    int ans = 1e9;
    for (int i = 0; i < b.size(); ++i)
    {
        if (c[i] != 1)
        {
            ans = min(ans, c[i]);
        }
    }
    if (ans >= n)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
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