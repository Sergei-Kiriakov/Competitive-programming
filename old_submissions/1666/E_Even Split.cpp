#include <bits/stdc++.h>

//#define int long long

using namespace std;

constexpr int mod = 998244353, MAXN = 2 * 1e5 + 5;

bool check1(vector<int> &a, int max_len, int len)
{
    int n = a.size();
    int now = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] - now > max_len)
        {
            return false;
        }
        now = min(now + max_len, a[i + 1]);
    }
    return len - now <= max_len;
}

int bin_ser1(vector<int> &a, int len)
{
    int l = 0, r = len;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (check1(a, mid, len))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return r;
}

bool check2(vector<int> &a, int min_len, int len)
{
    int n = a.size();
    int now = 0;
    for (int i = 0; i < n; ++i)
    {
        if (now > a[i])
        {
            return false;
        }
        now = max(now + min_len, a[i]);
    }
    return true;
}

int bin_ser2(vector<int> &a, int len)
{
    int l = 0, r = len + 1;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (check2(a, mid, len))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

pair<int, int> inter(pair<int, int> a, pair<int, int> b)
{
    return {max(a.first, b.first), min(a.second, b.second)};
}

void solve()
{
    int len, n;
    cin >> len >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int max_len = bin_ser1(a, len);
    int min_len = bin_ser2(a, len);
    vector<int> c(n + 1, 0), d(n + 1, 0);
    a.push_back(len);
    for (int i = 0; i < n; ++i)
    {
        d[i + 1] = min(d[i] + max_len, a[i + 1]);
        c[i + 1] = max(c[i] + min_len, a[i]);
    }
    vector<int> ans(n + 2, len);
    for (int i = n - 1; i > -1; --i)
    {
        pair<int, int> seg1 = {c[i], d[i]}, seg2 = {ans[i + 1] - max_len, ans[i + 1] - min_len};
        ans[i] = inter(seg1, seg2).first;
    }
    ans[n] = len;
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << " " << ans[i + 1] << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tt;
    // cin >> tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }
}

/*
*/