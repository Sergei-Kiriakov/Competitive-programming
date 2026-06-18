#include <bits/stdc++.h>

#define Please return
#define Accepted 0
#define int long long
#define endl "\n"
#define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod1 = 1e9 + 9, d = 179, mod2 = 1e9 + 7;


void solve()
{
    int n, k;
    cin >> n >> k;
    int m = (n + 1) / 2;
    vector<int> ans(n, -1);
    int d = n;
    for (int i = 0; i < n; i += 2)
    {
        ans[i] = d;
        --d;
    }
    int l = 1;
    for (int i = 1; i < n; i += 2)
    {
        ans[i] = l;
        ++l;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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
No brain
*/
