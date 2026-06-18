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

constexpr int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int max1 = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        max1 = max(max1, a[i]);
    }
    vector<int> ans(max1 + 1);
    for (int i = 0; i < n; ++i)
    {
        int c = 0;
        if (i == 0 or a[i] > a[i - 1]) ++c;
        if (i + 1 < n and a[i + 1] > a[i]) --c;
        int r = a[i];
        ans[r] += c;
        while (r > 0)
        {
            int el = (a[i] + r - 1) / r;
            int l = (a[i] + el - 1) / el;
            ans[l - 1] += el * c;
            ans[r] -= el * c;
            r = l - 1;
        }
    }
    int now = 0;
    for (int i = 0; i < max1; ++i)
    {
        now += ans[i];
        cout << now << " ";
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
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/