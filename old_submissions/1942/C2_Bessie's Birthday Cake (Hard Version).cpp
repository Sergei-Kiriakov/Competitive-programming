//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod1 = 1e9 + 7, mod2 = 1e9 + 9;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(x);
    set<int> s;
    for (int i = 0; i < x; ++i)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    sort(all(a));
    int ans = x;
    for (int i = 0; i < x - 1; ++i)
    {
        int j = i + 1;
        if (abs(a[i] - a[j]) == 2 and s.count((a[i] + a[j]) / 2) == 0)
        {
            ++ans;
        }
    }
    if ((a[0] == 1 and a[x - 1] == n - 1 and s.count(n) == 0) or (a[0] == 2 and a[x - 1] == n and s.count(1) == 0))
        ++ans;
    int ans1 = ans - 2;
    vector<vector<int>> b;
    for (int i = 0; i < x - 1; ++i)
    {
        int kk = a[i + 1] - a[i] - 1;
        b.push_back({-(kk % 2), kk - kk % 2});
    }
    int kk = n - a[x - 1] + a[0] - 1;
    b.push_back({-(kk % 2), kk - kk % 2});
    sort(all(b));
    for (int i = 0; i < b.size(); ++i)
    {
        int xx = b[i][1] - b[i][0];
        if (xx <= 1)
            continue;
        if (y >= xx / 2)
        {
            ans += xx;
            y -= xx / 2;
        }
        else if (y > 0)
        {
            ans += y * 2;
            y = 0;
        }
    }
    cout << ans - 2 << endl;
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
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