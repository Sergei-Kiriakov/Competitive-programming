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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector<int> a1 = a, b1 = b;
    n = a1.size();
    vector<vector<int> > d;
    for (int i = 0; i < n; ++i)
    {
        d.push_back({b1[i], a1[i]});
    }
    sort(all(d));
    multiset<int> s;
    int sum_s = 0;
    for (int i = n - 1; i > n - k - 1; --i)
    {
        s.insert(d[i][1]);
        sum_s += d[i][1];
    }
    int now = 0;
    for (int i = 0; i < n - k; ++i)
    {
        now += max(d[i][0] - d[i][1], 0ll);
    }
    int ans = max(0ll, now - sum_s);
    for (int i = n - k - 1; i > -1; --i)
    {
        now -= max(d[i][0] - d[i][1], 0ll);
        sum_s += d[i][1];
        s.insert(d[i][1]);
        while (s.size() > k)
        {
            sum_s -= *(--s.end());
            s.erase(--s.end());
        }
        ans = max(ans, now - sum_s);
    }
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