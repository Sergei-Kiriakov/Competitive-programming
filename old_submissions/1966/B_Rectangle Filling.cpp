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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    if (s[0][0] == s.back().back() or s.back()[0] == s[0].back())
    {
        cout << "YES" << endl;
        return;
    }
    if (s[0][0] == s[0].back())
    {
        for (int i = 0; i < m; ++i)
        {
            if (s[0][0] != s[0][i])
            {
                cout << "YES" << endl;
                return;
            }
        }
        for (int i = 0; i < m; ++i)
        {
            if (s.back()[0] != s.back()[i])
            {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
        return;
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (s[0][0] != s[i][0])
            {
                cout << "YES" << endl;
                return;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (s[0].back() != s[i].back())
            {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
        return;
    }
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