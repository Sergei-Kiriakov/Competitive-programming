#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179, MAX = 1e5 + 5;

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int t, k;
    cin >> t >> k;
    vector<int> dp(MAX, 0);
    dp[0] = 1;
    for (int i = 1; i < MAX; ++i)
    {
        if (i - k > -1)
            dp[i] = (dp[i - 1] + dp[i - k]) % mod;
        else
            dp[i] = dp[i - 1];
    }
    vi pref_sum(MAX, 0);
    pref_sum[0] = dp[0];
    for (int i = 1; i < MAX; ++i)
    {
        pref_sum[i] = (pref_sum[i - 1] + dp[i]) % mod;
    }
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << (mod + pref_sum[r] - pref_sum[l - 1]) % mod << "\n";
    }
    //solve();
    return 0;
}
