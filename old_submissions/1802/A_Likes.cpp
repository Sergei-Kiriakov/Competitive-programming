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
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] < 0)
            ++cnt1;
        if (a[i] > 0)
            ++cnt2;
    }
    for (int i = 1; i <= cnt2; ++i)
    {
        cout << i << " ";
    }
    for (int i = cnt2 - 1; i >= cnt2 - cnt1; --i)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < cnt1 * 2; ++i)
    {
        if (i % 2 == 0)
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }
    for (int i = 1; i <= cnt2 - cnt1; ++i)
    {
        cout << i << " ";
    }
    cout << endl;
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
1
codeforces
atcoder
*/