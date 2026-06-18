#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179, MAX = 1e4 * 4;

void solve()
{
    int n, t;
    cin >> n >> t;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int ans = 0;
    int left = 0, right = 0, now_sum = a[0];
    while(left < n)
    {
        while ((right + 1 < n && now_sum + a[right + 1] <= t) || right + 1 <= left)
        {
            now_sum += a[right + 1];
            ++right;
        }
        if (now_sum <= t)
        {
            ans = max(ans, right - left + 1);
        }
        now_sum -= a[left];
        ++left;
    }
    cout << ans << "\n";
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    solve();
    //solve();
    return 0;
}
