#include <bits/stdc++.h>

#define int long long

using namespace std;

constexpr int mod = 998244353;

bool check (int p, int k, int n, int m)
{
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += min(p / i, m);
    }
    for (int i = 1; i <= m; ++i)
    {
        ans += min(p / i, n);
    }
    return ans / 2 < k;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int l = 0, r = n * m;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (check(mid, k, n, m))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << r << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
}

/*

*/