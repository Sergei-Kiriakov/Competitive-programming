#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 7, ddl = 179;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    if (n % 2 == 0)
    {
        int max1 = 0, min1 = 0;
        for (int i = 0; i < n; ++i) max1 ^= a[i];
        int now = 0;
        for (int i = 0; i < m; ++i) now |= b[i];
        for (int i = 0; i < n; ++i) min1 ^= (a[i] | now);
        cout << min1 << " " << max1 << endl;
    }
    else
    {
        int max1 = 0, min1 = 0;
        for (int i = 0; i < n; ++i) min1 ^= a[i];
        int now = 0;
        for (int i = 0; i < m; ++i) now |= b[i];
        for (int i = 0; i < n; ++i) max1 ^= (a[i] | now);
        cout << min1 << " " << max1 << endl;
    }
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(0);
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