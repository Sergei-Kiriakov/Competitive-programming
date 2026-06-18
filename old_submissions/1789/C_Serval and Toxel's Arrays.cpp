#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod = 1e9 + 7, d = 179;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> cnt(n + m + 1, 0);
    vector<int> cnt_em(n + m + 1, 0), last(n + m + 1, -1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++cnt[a[i]];
        last[a[i]] = 0;
    }
    for (int i = 1; i < m + 1; ++i)
    {
        int p, w;
        cin >> p >> w;
        --p;
        --cnt[a[p]];
        if (cnt[a[p]] == 0)
        {
            last[a[p]] = i - 1;
        }
        if (cnt[w] == 0)
        {
            cnt_em[w] += i - last[w] - 1;
            last[w] = i;
        }
        a[p] = w;
        ++cnt[w];
    }
    for (int i = 0; i < n + m + 1; ++i)
    {
        if (cnt[i] > 0)
        {
            last[i] = m;
        }
    }
    int ans = 0;
    for (int i = 0; i < n + m + 1; ++i)
    {
        cnt_em[i] += m - last[i];
    }
    for (int i = 0; i < n + m + 1; ++i)
    {
        ans += m * (m + 1) / 2 - cnt_em[i] * (cnt_em[i] - 1) / 2;
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}

/*
...
*/