#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<vector<int> >  dp(3, vector<int> (n + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 1 || a[i] == 3)
        {
            dp[1][i + 1] = min(dp[2][i], dp[0][i]);
        }
        if (a[i] == 2 || a[i] == 3)
        {
            dp[2][i + 1] = min(dp[1][i], dp[0][i]);
        }
        dp[0][i + 1] = min({dp[0][i], dp[1][i], dp[2][i]}) + 1;
    }
    cout << min({dp[0][n], dp[1][n], dp[2][n]}) << endl;
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    /*
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    */
    solve();
    return 0;
}
/*
1
R228C494

RZ228
*/
