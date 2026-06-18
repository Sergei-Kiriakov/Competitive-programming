#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93;

void solve()
{
    int big = 1e18;
    vector<int> _calc = {1};
    for (int i = 2; i < 1e6 + 6; ++i)
        for (int j = i * i * i; j <= big; j *= i)
        {
            _calc.push_back(j);
            if (j > big / i)
                break;
        }
    sort(all(_calc));
    _calc.erase(unique(all(_calc)), _calc.end());
    vector<int> calc;
    for (auto x : _calc)
    {
        int d = sqrtl(x);
        if (d * d != x)
            calc.push_back(x);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        int ans = upper_bound(all(calc), r) - lower_bound(all(calc), l);
        ans += (int) sqrtl(r) - (int) sqrtl(l - 1);
        cout << ans << endl;
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
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/