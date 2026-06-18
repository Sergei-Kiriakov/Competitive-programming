//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define remin(x, y) x = min(x, y)
#define remax(x, y) x = max(x, y)
#define lowpos(a, x) int(lower_bound(a.begin(), a.end(), x) - a.begin())
#define uppos(a, x) int(upper_bound(a.begin(), a.end(), x) - a.begin())

using namespace std;

constexpr int mod = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> c(101);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++c[a[i]];
    }
    sort(all(c));
    reverse(all(c));
    int free = 0;
    int ans = 0;
    for (int i = 0; i < 101; ++i)
    {
        free += c[i] / k * (k - 1);
        c[i] %= k;
    }
    sort(all(c));
    reverse(all(c));
    for (int i = 0; i < 101; ++i)
    {
        if (free >= k - c[i] and c[i] != 0)
        {
            free -= k - c[i];
            free += k - 1;
            c[i] = 0;
        }
    }
    for (int i = 0; i < 101; ++i)
        ans += c[i];
    ans += min(free, k - 1);
    cout << ans << endl;
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
//    cout << fixed;
//    cout.precision(7);
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