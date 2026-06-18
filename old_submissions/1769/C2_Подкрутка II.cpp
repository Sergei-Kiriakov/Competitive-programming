#include <bits/stdc++.h>

#define Please return
#define Accepted 0
#define int long long
#define endl "\n"
#define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod = 998244353;

void solve ()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> d(MAXN, 0);
    for (int i = 0; i < n; ++i)
    {
        d[a[i] + 1] = d[a[i]] + 1;
        d[a[i]] = d[a[i] - 1] + 1;
    }
    int ans = 0;
    for (int i = 0; i < MAXN; ++i)
    {
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}

/*
0 1
4
1 2 2 5
1 2 3 5
3 2 2 1 1 
*/
