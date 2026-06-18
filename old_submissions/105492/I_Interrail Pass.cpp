// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <functional>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <bitset>
#include <random>
#include <chrono>
#include <cassert>
#include <memory>

#define int long long
//#define double long double
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

const int maxn = 2e5 + 5;

int solve(int n, int k, vector<vector<int> > days, vector<vector<int> > tariffs)
{
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    vector<int> prev(1e6 + 6, 0);
    int jj = n - 1;
    for (int i = prev.size(); i > -1; --i) {
        while (jj - 1 > -1 and days[jj - 1][0] >= i) {
            --jj;
        }
        prev[i] = jj;
    }
    for (int i = 0; i < n; ++i) {
        int t = days[i][0], f = days[i][1];
        dp[i + 1] = dp[i] + f;
        for (int j = 0; j < k; ++j) {
            int p = tariffs[j][0], d = tariffs[j][1], c = tariffs[j][2];
            dp[i + 1] = min(dp[max(i - d + 1, prev[max(t - p + 1, 0ll)])] + c, dp[i + 1]);
        }
    }
    return dp[n];
}

void input()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int> > days(n, vector<int> (2));
    for (int i = 0; i < n; ++i) {
        cin >> days[i][0] >> days[i][1];
    }
    vector<vector<int> > tariffs(k, vector<int> (3));
    for (int i = 0; i < k; ++i) {
        cin >> tariffs[i][0] >> tariffs[i][1] >> tariffs[i][2];
    }
    int ans = solve(n, k, days, tariffs);
    cout << ans << endl;
}

int32_t main()
{
    // ofstream cout("");
    // ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
//    cin >> tt;
    while(tt-->0)
    {
        input();
    }
}

/*
1
3
6 4 5
1 2 3
*/