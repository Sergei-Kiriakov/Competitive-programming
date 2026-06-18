#include <bits/stdc++.h>
#define int long long
#define double long double

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vvvi = std::vector<vvi>;
using vvvvi = std::vector<vvvi>;
using vb = std::vector<bool>;
using vvb = std::vector<vb>;
using pii = std::pair<int, int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
using mii = std::map<int, int>;
using ull = unsigned long long;
using vs = std::vector<std::string>;

using namespace std;

constexpr int MOD = 1e9 + 7, P = 179, maxn = 300 + 3;
const int n = 31, m = 31, k = 51;

int dp[n][m][k];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            for (int l = 0; l < k; ++l)
            {
                if ((i == 1 && j == 1 && l == 1) || l == i * j || l == 0)
                {
                    dp[i][j][l] = 0;
                }
                else
                {
                    dp[i][j][l] = 1e9;
                }
            }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            for (int l = 1; l < k; ++l)
            {
                for (int h = 1; h < j; ++h)
                {
                    for (int l1 = 0; l1 < l; ++l1)
                    {
                        dp[i][j][l] = min(dp[i][h][l - l1] + dp[i][j - h][l1] + i * i, dp[i][j][l]);
                    }
                }
                for (int h = 1; h < i; ++h)
                {
                    for (int l1 = 0; l1 < l; ++l1)
                    {
                        dp[i][j][l] = min(dp[h][j][l - l1] + dp[i - h][j][l1] + j * j, dp[i][j][l]);
                    }
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int nn, mm, kk;
        cin >> nn >> mm >> kk;
        cout << dp[nn][mm][kk] << endl;
    }
}

/*
1
6
)((()(
*/
