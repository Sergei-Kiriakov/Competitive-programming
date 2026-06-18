#include <bits/stdc++.h>

#define int long long
//#define endl "\n"

using namespace std;

const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    vector<pair<int, int> > cnt(2 * n + 1, {0, 0});
    int len = 1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[i - 1])
        {
            cnt[a[i - 1]].first = max(len, cnt[a[i - 1]].first);
            len = 1;
        }
        else
        {
            ++len;
        }
    }
    cnt[a[n - 1]].first = max(len, cnt[a[n - 1]].first);
    len = 1;
    for (int i = 1; i < n; ++i)
    {
        if (b[i] != b[i - 1])
        {
            cnt[b[i - 1]].second = max(len, cnt[b[i - 1]].second);
            len = 1;
        }
        else
        {
            ++len;
        }
    }
    cnt[b[n - 1]].second = max(len, cnt[b[n - 1]].second);
    int ans = 0;
    for (int i = 0; i < cnt.size(); ++i)
    {
        ans = max(ans, cnt[i].first + cnt[i].second);
    }
    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // cout << fixed;
    // cout.precision(15);
    int tt = 1;
    cin >> tt;
    while (tt-->0)
    {
        solve();
    }
}


/*
*/