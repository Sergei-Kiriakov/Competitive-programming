#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n), b(n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (n == 2)
    {
        cout << abs(a[0] - a[1]) << endl;
        return;
    }
    if (n == 4)
    {
        vector<vector<int> > res;
        res.push_back({0, 0, 0, 0});
        res.push_back({2, -1, -1, -1});
        res.push_back({-1, 2, -1, -1});
        res.push_back({-1, -1, 2, -1});
        res.push_back({-1, -1, -1, 2});
        res.push_back({2, 2, 2, 2});
        int ans = 1e10;
        for (int i = 0; i < res.size(); ++i)
        {
            int now = 0;
            for (int j = 0; j < n; ++j)
            {
                now += abs(res[i][j] - a[j]);
            }
            ans = min(ans, now);
        }
        cout << ans << endl;
        return;
    }
    if ((n / 2) % 2 == 0)
    {
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; ++i)
        {
            ans1 += abs(a[i]);
            if (i != n - 1)
                ans2 += abs(a[i] + 1);
            else
                ans2 += abs(a[i] - n / 2);
        }
        cout << min(ans1, ans2) << endl;
        return;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += abs(a[i]);
    }
    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cerr.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    int tt = 1;
    cin >> tt;
    while (tt-->0)
    {
        solve();
    }
    return 0;
}


/*
-1 -1 -1 2
0 0 0 0
2 2 2 2

0 0 0 0 0 0
-1 -1 -1 -1 -1 1


*/