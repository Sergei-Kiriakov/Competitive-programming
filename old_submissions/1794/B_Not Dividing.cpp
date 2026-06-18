#include <bits/stdc++.h>

#define int long long
#define endl "\n"

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
    if (a[0] == 1)
    {
        ++a[0];
    }
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == 1)
        {
            ++a[i];
        }
        while (a[i] % a[i - 1] == 0)
        {
            ++a[i];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cerr.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
1
6 2 -8
4 -1 9 -3 7 -8
*/