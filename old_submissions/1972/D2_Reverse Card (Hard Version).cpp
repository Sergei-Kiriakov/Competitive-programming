//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int p = 1; p * p <= n; ++p)
    {
        for (int q = 1; q * q <= m; ++q)
        {
            if (gcd(p, q) == 1)
            {
                ans += min(n / p, m / q) / (p + q);
            }
        }
    }
    cout << ans << endl;
}

int32_t main()
{
//    ofstream cout("");
//    ifstream cin("");
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