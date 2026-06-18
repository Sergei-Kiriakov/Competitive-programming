#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

constexpr int MAXN = 10, mod = 998244353;

void solve ()
{
    int n, x;
    cin >> n >> x;
    if (n % x != 0)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> ans(n);
    ans[0] = x;
    ans[n - 1] = 1;
    for (int i = 1; i < n - 1; ++i)
    {
        ans[i] = i + 1;
    }
    n /= x;
    int f = x;
    int d = 2;
    while (n != 1)
    {
        if (n % d == 0)
        {
            ans[f - 1] = f * d;
            f *= d;
            n /= d;
        }
        else
        {
            ++d;
        }
    }
    for (int i = 0; i < ans.size(); ++i)
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
1011
1001
*/