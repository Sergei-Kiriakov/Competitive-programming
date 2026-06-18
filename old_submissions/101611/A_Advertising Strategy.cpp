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

void solve()
{
    int n, k;
    cin >> n >> k;
    int min1 = 1e18;
    for (int k1 = 1; k1 < k; ++k1)
    {
        int ans = 1;
        int d = k1;
        int l = k - k1;
        while (d < n - l)
        {
            d = d + min(d, (n - d) / 2);
            ++ans;
        }
        min1 = min(ans, min1);
    }
    cout << min1 << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    //cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/