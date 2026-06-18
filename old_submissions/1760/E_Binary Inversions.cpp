#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

constexpr int MAXN = 10, mod = 998244353;

void solve ()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> pr_0(n + 1, 0), pr_1(n + 1, 0);
    for (int i = 1; i < n + 1; ++i)
    {
        pr_0[i] = pr_0[i - 1] + (a[i - 1] == 0);
        pr_1[i] = pr_1[i - 1] + (a[i - 1] == 1);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
        {
            ans += pr_1[i];
        }
    }
    // cout << ans << endl;
    int max1 = ans;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
        {
            ans = max(ans, max1 - pr_1[i] + pr_0[n] - pr_0[i + 1]);
        }
        else
        {
            ans = max(ans, max1 + pr_1[i] - pr_0[n] + pr_0[i]);
        }
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
*/