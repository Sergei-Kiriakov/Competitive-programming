//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int bal = 0;
    map<int, int>gg;
    int ans = 0;
    gg[0] = -1;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
            --bal;
        else
            ++bal;
        if (gg.count(bal) == 0)
        {
            gg[bal] = i;
        }
        else
        {
            ans = max(ans, i - gg[bal]);
        }
    }
    cout << ans << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
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