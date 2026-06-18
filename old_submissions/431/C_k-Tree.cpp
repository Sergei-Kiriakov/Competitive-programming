#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179, MAX = 1e4 * 4;

vector<vector<int> > dp(2);

int k, d;

int f (int n, int c)
{
    if (dp[c][n] == -1)
    {
        dp[c][n] = 0;
        for (int i = 1; i < k + 1 && n - i > -1; ++i)
        {
            if (c == 1)
            {
                if (i >= d)
                {
                    dp[c][n] += f(n - i, 0) + f(n - i, 1);
                }
                else
                {
                    dp[c][n] += f(n - i, 1);
                }
            }
            else
            {
                if (i < d)
                {
                    dp[c][n] += f(n - i, 0);
                }
            }
        }
        dp[c][n] %= mod;
    }
    return dp[c][n];
}

void solve()
{
    int n;
    cin >> n >> k >> d;
    dp[0].resize(n + 1, -1);
    dp[1].resize(n + 1, -1);
    dp[0][0] = 1;
    cout << f(n, 1) << "\n";
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
