//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

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
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 0; i < n; ++i) ans = (ans * 2) % mod;
    if (n % 3 != 2)
    {
        cout << ans << endl;
        return;
    }
    int k = n / 3;
    int dif = 1;
    for (int i = 0; i < k + 1; ++i) dif = (dif * 2) % mod;
    cout << (mod + ans - dif) % mod << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(0);
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