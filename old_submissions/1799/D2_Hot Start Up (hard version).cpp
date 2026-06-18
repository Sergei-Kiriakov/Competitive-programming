#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod = 1e9 + 7, d = 179;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a1(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a1[i];
        --a1[i];
    }
    vector<int> cold(k), hot(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> cold[i];
    }
    for (int i = 0; i < k; ++i)
    {
        cin >> hot[i];
    }
    vector<int> a = {a1[0]};
    int ans = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a1[i] != a1[i - 1])
        {
            a.push_back(a1[i]);
        }
        else
        {
            ans += hot[a1[i]];
        }
    }
    n = a.size();
    vector<int> preff(n);
    preff[0] = cold[a[0]];
    for (int i = 1; i < n; ++i)
    {
        preff[i] = preff[i - 1] + cold[a[i]];
    }
    vector<int> dp(n, 1e9);
    dp[0] = cold[a[0]];
    vector<int> prev(k, -1), last(k, -1);
    last[a[0]] = 0;
    // vector<int> vost(n, -1);
    for (int i = 1; i < n; ++i)
    {
        if (last[a[i]] != -1)
        {
            prev[a[i]] = last[a[i]];
        }
        last[a[i]] = i;
        if (prev[a[i]] != -1)
        {
            int l = dp[prev[a[i]] + 1] + preff[i - 1] - preff[prev[a[i]] + 1] + hot[a[i]];
            // if (l < dp[i - 1] + cold[a[i]])
            // {
            //     vost[i] = prev[a[i]];
            // }
            dp[i] = min(dp[i - 1] + cold[a[i]], l);
        }
        else
        {
            dp[i] = dp[i - 1] + cold[a[i]];
        }
    }
    cout << dp[n - 1] + ans << endl;
    // vector<bool> used_for_two(n, false);
    // int i = n - 1;
    // while (i > -1)
    // {
    //     if (vost[i] != -1)
    //     {
    //         used_for_two[i] = true;
    //         i = vost[i];
    //         used_for_two[i] = true;
    //     }
    //     else
    //     {
    //         --i;
    //     }
    // }
    // vector<int> ans1, ans2;
    // for (int j = 0; j < n; ++j)
    // {
    //     if (used_for_two[j])
    //     {
    //         ans2.push_back(a[j]);
    //     }
    //     else
    //     {
    //         ans1.push_back(a[j]);
    //     }
    // }
    // int ans = 0;
    // if (ans1.size() != 0)
    // {
    //     ans += cold[ans1[0]];
    // }
    // if (ans2.size() != 0)
    // {
    //     ans += cold[ans2[0]];
    // }
    // for (int j = 1; j < ans1.size(); ++j)
    // {
    //     if (ans1[j - 1] == ans1[j])
    //     {
    //         ans += hot[ans1[j]];
    //     }
    //     else
    //     {
    //         ans += cold[ans1[j]];
    //     }
    // }
    // for (int j = 1; j < ans2.size(); ++j)
    // {
    //     if (ans2[j - 1] == ans2[j])
    //     {
    //         ans += hot[ans2[j]];
    //     }
    //     else
    //     {
    //         ans += cold[ans2[j]];
    //     }
    // }
    // cout << ans << endl;
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
1
5 2
2 1 2 1 1
65 45
54 7
*/