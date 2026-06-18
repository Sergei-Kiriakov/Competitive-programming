#include <bits/stdc++.h>
#define int long long

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<vvi> vvvi;
typedef std::vector<std::string> vs;
typedef std::vector<bool> vb;
typedef std::vector<vb> vvb;
typedef std::vector<double> vd;
typedef std::vector<vd> vvd;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
typedef std::vector<vpii> vvpii;

using namespace std;

constexpr int mod = 998244353, p = 179;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pii normal(int a)
{
    pii ans;
    if (a == 0)
    {
        ans = {0, 0};
    }
    else if (a == 1)
    {
        ans = {1, 0};
    }
    else if (a == 2)
    {
        ans = {0, 1};
    }
    else
    {
        ans = {1, 1};
    }
    return ans;
}

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n, k;
    cin >> n >> k;
    vvvi dp(n + 10, vvi (k + 10, vi (4, 0)));
    dp[0][1][0] = 1;
    dp[0][1][3] = 1;
    dp[0][2][1] = 1;
    dp[0][2][2] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < k + 1; ++j)
        {
            for (int bit1 = 0; bit1 < 4; ++bit1)
            {
                for (int bit2 = 0; bit2 < 4; ++bit2)
                {
                    int x1, y1, x2, y2;
                    tie(x1, y1) = normal(bit1);
                    tie(x2, y2) = normal(bit2);
                    if (x1 == y1)
                    {
                        if (x2 != y2)
                        {
                            dp[i + 1][j + 1][bit2] = (dp[i + 1][j + 1][bit2] + dp[i][j][bit1]) % mod;
                        }
                        else
                        {
                            if (x2 == x1)
                            {
                                dp[i + 1][j][bit2] = (dp[i + 1][j][bit2] + dp[i][j][bit1]) % mod;
                            }
                            else
                            {
                                dp[i + 1][j + 1][bit2] = (dp[i + 1][j + 1][bit2] + dp[i][j][bit1]) % mod;
                            }
                        }
                    }
                    else
                    {
                        if (x2 == y2)
                        {
                            dp[i + 1][j][bit2] = (dp[i + 1][j][bit2] + dp[i][j][bit1]) % mod;
                        }
                        else
                        {
                            if (x1 == x2)
                            {
                                dp[i + 1][j][bit2] = (dp[i + 1][j][bit2] + dp[i][j][bit1]) % mod;
                            }
                            else
                            {
                                dp[i + 1][j + 2][bit2] = (dp[i + 1][j + 2][bit2] + dp[i][j][bit1]) % mod;
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = (dp[n - 1][k][0] + dp[n - 1][k][1] + dp[n - 1][k][2] + dp[n - 1][k][3]) % mod;
    /*
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < k + 1; ++j)
        {
            cout << "( " << dp[i][j][0] << " " << dp[i][j][1] <<  " " << dp[i][j][2] << " " << dp[i][j][3] << " )" << "    ";
        }
        cout << endl;
    }
    */
    cout << ans << endl;
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
