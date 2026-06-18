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
    int d = 1;
    int now = 0;
    vector<int> ans;
    if (n == 1)
    {
        cout << k << endl;
        return;
    }
    while (now + d <= k)
    {
        now += d;
        d *= 2;
    }
    ans.push_back(now);
    ans.push_back(k - now);
    while (ans.size() != n)
    {
        ans.push_back(0);
    }
    for (int el : ans)
    {
        cout << el << " ";
    }
    cout << endl;
    return;
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