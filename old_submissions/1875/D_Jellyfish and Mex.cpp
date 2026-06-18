//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 998244353, big = 2e6;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(all(a));
    int mexx = 0;
    int cnt0 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
            ++cnt0;
        if (mexx == a[i])
            ++mexx;
        if (a[i] > mexx)
            break;
    }
    vector<int> cnt(mexx, 0);
    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= mexx)
            continue;
        ++cnt[a[i]];
    }
    if (mexx == 0)
    {
        cout << 0 << endl;
        return;
    }
    vector<int> dp(mexx, 1e9);
    vector<int> last(mexx, 1e9);
    for (int i = mexx - 1; i > -1; --i)
    {
        if (i == 1)
            int op = 1;
        dp[i] = (cnt[i] - 1) * mexx;
        last[i] = mexx;
        for (int j = i + 1; j < mexx; ++j)
        {
            if (dp[i] > dp[j] + cnt[i] * j)
            {
                last[i] = j;
                dp[i] = dp[j] + cnt[i] * j;
            }
        }
    }
    cout << dp[0] << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
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