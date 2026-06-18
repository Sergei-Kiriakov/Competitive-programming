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

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int solve (int n, int k, vector<int> a) {
    vector<int> b;
    vector<int> cnt;
    int last = -1;
    for (int i= 0 ; i < n; ++i) {
        if (a[i] > last) {
            b.push_back(a[i]);
            cnt.push_back(1);
            last = a[i];
        }
        else {
            ++cnt.back();
        }
    }
    int mm = b.size();
    vector<vector<vector<int> > > dp(mm + 1, vector<vector<int> > (k + 1, vector<int> (k + 1, - 1)));
    dp[0][0][0] = 0;
    for (int i = 1; i <= mm; ++i) {
        vector<vector<int> > maxdp(k + 1, vector<int> (k + 1, 0));
        for (int s = 0; s <= k; ++s) {
            maxdp[s][0] = dp[i - 1][s][0];
            for (int j = 1; j <= k; ++j) {
                maxdp[s][j] = max(maxdp[s][j - 1], dp[i - 1][s][j]);
            }
            for (int m = 0; m <= s; ++m) {
                dp[i][s][m] = dp[i - 1][s][m];
                if (b[i - 1] >= m) {
                    dp[i][s][m] = max(dp[i][s][m], maxdp[s - m][m]);
                }
                if (dp[i][s][m] > -1) {
                    dp[i][s][m] += m * cnt[i - 1];
                }
            }
        }
    }
    int ans = 0;
    for (int s = 0; s <= k; ++s) {
        for (int m = 0; m <= k; ++m) {
            ans = max(ans, dp[mm][s][m]);
        }
    }
    return ans;
}

void input() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto ans = solve(n, k, a);
    cout << ans << endl;
}

int32_t main()
{
    int tt = 1;
    cin >> tt;

    while (tt-->0)
    {
        input();
    }
}
