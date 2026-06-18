//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

void sdvig (vector<int> & a, int k) {
    vector<int> ans(a.size());
    for (int i = 0; i < a.size(); ++i) {
        ans[(a.size() + i - k) % a.size()] = a[i];
//        ans[(i + k) % a.size()] = a[i];
    }
    a = ans;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > a(n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<int> > dp(n, vector<int> (m, 1e18));
    for (int line_ind = 0; line_ind < n; ++line_ind) {
        for (int sd = 0; sd < m; ++sd) {
            vector<int> new_line = a[line_ind];
            sdvig(new_line, sd);
            vector<int> dp_now(m, 1e18);
            dp_now[0] = new_line[0] + sd * k;
            if (line_ind != 0) {
                dp_now[0] += dp[line_ind - 1][0];
            }
            for (int col_ind = 0; col_ind < m; ++col_ind) {
                if (col_ind == 0 and line_ind == 0) {
                    dp[line_ind][col_ind] = min(dp[line_ind][col_ind], new_line[col_ind] + sd * k);
                    continue;
                }
                if (line_ind != 0) {
                    dp_now[col_ind] = min(dp_now[col_ind], dp[line_ind - 1][col_ind] + new_line[col_ind] + sd * k);
                }
                if (col_ind != 0) {
                    dp_now[col_ind] = min(dp_now[col_ind], dp_now[col_ind - 1] + new_line[col_ind]);
                }
                dp[line_ind][col_ind] = min(dp[line_ind][col_ind], dp_now[col_ind]);
            }
        }
    }
    cout << dp[n - 1][m - 1] << endl;
}

int32_t main()
{
//    ofstream cout("");
//    ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}

/*
*/