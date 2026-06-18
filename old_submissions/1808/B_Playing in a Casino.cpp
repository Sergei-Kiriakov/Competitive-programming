#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

int f (int n)
{
    int min1 = 10, max1 = -1;
    while (n != 0)
    {
        min1 = min(n % 10, min1);
        max1 = max(max1, n % 10);
        n /= 10;
    }
    return max1 - min1;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int> (m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int> > b(m, vector<int> (n, 0));
    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        vector<int> c(n);
        for (int j = 0; j < n; ++j)
        {
            c[j] = a[j][i];
        }
        sort(c.begin(), c.end());
        for (int j = 1; j < n; ++j)
        {
            ans += (c[j] - c[j - 1]) * (n - j) * j;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    int tt = 1;
    cin >> tt;
    while (tt-->0)
    {
        solve();
    }
}


/*
*/