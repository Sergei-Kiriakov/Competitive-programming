#include <bits/stdc++.h>

#define int long long
//#define double long double

using namespace std;

constexpr int mod = 1e9 + 7;

int sum (vector<int> &a)
{
    int ans = 0;
    for (int elem : a) ans += elem;
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int> > dp(2, vector<int> (4, 0));
    dp[0][0] = 0; // A
    dp[0][1] = 0; // B
    dp[0][2] = 0; // C
    dp[0][3] = 1; // D
    for (int i = 1; i < n + 1; ++i)
    {
        int j1 = i % 2, j2 = (i + 1) % 2;
        int sum1 = sum(dp[j2]) + mod;
        dp[j1][0] = (sum1 - dp[j2][0]) % mod;
        dp[j1][1] = (sum1 - dp[j2][1]) % mod;
        dp[j1][2] = (sum1 - dp[j2][2]) % mod;
        dp[j1][3] = (sum1 - dp[j2][3]) % mod;
    }
    cout << dp[n % 2][3] << "\n";
}


int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    //solve();
    return 0;
}

/*
*/
