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
    int n, k, x;
    cin >> n >> k >> x;
    if (k > n || k > x + 1)
    {
        cout << -1 << endl;
        return;
    }
    if (k + 1 > x)
        cout << k * (k - 1) / 2 + (k - 1) * (n - k) << endl;
    else
        cout << k * (k - 1) / 2 + x * (n - k) << endl;
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