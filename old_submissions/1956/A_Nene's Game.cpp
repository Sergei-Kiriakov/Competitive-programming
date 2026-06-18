//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

//#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define remin(x, y) x = min(x, y)
#define remax(x, y) x = max(x, y)
#define lowpos(a, x) int(lower_bound(a.begin(), a.end(), x) - a.begin())
#define uppos(a, x) int(upper_bound(a.begin(), a.end(), x) - a.begin())

using namespace std;

constexpr int mod = 998244353;

void solve()
{
    int k, q;
    cin >> k >> q;
    vector<int> a(k);
    int min1 = 1e9;
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
        min1 = min(a[i], min1);
    }
    vector<int> qq(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> qq[i];
        cout << min(min1 - 1, qq[i]) << " ";
    }
    cout << endl;
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
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