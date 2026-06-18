//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93, ddl = 179;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), cost(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> cost[i];
    int ans = 1e9;
    for (int j = 1; j < n - 1; ++j)
    {
        int min1 = 1e9;
        for (int i = 0; i < j; ++i)
            if (a[i] < a[j])
                min1 = min(min1, cost[i]);
        int min2 = 1e9;
        for (int k = n - 1; k > j; --k)
            if (a[k] > a[j])
                min2 = min(min2, cost[k]);
        ans = min(ans, min2 + min1 + cost[j]);
    }
    if (ans == 1e9)
    {
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
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