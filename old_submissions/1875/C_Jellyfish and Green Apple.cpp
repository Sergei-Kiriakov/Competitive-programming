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
    int n, m;
    cin >> n >> m;
    int ans = 0;
    n %= m;
    int cnt = 0;
    while (n)
    {
        if (cnt > 30)
            break;
        ans += n;
        n *= 2;
        n %= m;
        ++cnt;
    }
    if (n == 0)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int32_t main()
{
//  ofstream cout("sum.out");
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