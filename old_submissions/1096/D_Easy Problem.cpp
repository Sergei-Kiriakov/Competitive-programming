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

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vvi dp(n + 1, vi (4, 1e9));
    dp[0][0] = 0;
    for (int i = 1; i < n + 1; ++i)
    {
        char c = s[i - 1];
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 1][2];
        dp[i][3] = dp[i - 1][3];
        if (c == 'h')
        {
            dp[i][0] += a[i - 1];
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]);
        }
        else if (c == 'a')
        {
            dp[i][1] += a[i - 1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
        }
        else if (c == 'r')
        {
            dp[i][2] += a[i - 1];
            dp[i][3] = min(dp[i - 1][3], dp[i - 1][2]);
        }
        else if (c == 'd')
        {
            dp[i][3] += a[i - 1];
        }
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}) << endl;
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
