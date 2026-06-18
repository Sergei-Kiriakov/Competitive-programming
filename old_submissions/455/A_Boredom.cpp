#include <bits/stdc++.h>
#define int int64_t

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;

using namespace std;

const int MAXN = 1e5 + 5;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n;
    cin >> n;
    vi a(n), c(MAXN);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++c[a[i]];
    }
    vi dp(MAXN, 0);
    dp[1] = c[1];
    dp[2] = max(c[2] * 2, dp[1]);
    for (int i = 3; i < MAXN; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + c[i] * i);
    }
    int ans = 0;
    for (int i = 0; i < MAXN; ++i)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}
