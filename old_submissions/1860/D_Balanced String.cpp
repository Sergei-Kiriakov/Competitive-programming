//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

//#define int long long
//#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93;

void solve()
{
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0, n = s.size();
    for (int i = 0; i < n; ++i)
    {
        cnt0 += (s[i] == '0');
        cnt1 += (s[i] == '1');
    }
    int big = n * n / 2;
    vector<vector<vector<int> > > dp(n + 5, vector<vector<int> > (n + 5, vector<int> (big + 5, 1e9)));
    dp[0][0][0] = (s[0] == '0');
    dp[0][1][0] = (s[0] == '1');
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < big; ++k)
            {
                dp[i + 1][j + 1][k] = min(dp[i][j][k] + (s[i + 1] == '1'), dp[i + 1][j + 1][k]);
                dp[i + 1][j][min(k + j, big)] = min(dp[i][j][k] + (s[i + 1] == '0'), dp[i + 1][j][min(k + j, big)]);
            }
        }
    }
    int need = cnt1 * cnt0 / 2;
    cout << dp[n - 1][cnt0][need] / 2 << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/