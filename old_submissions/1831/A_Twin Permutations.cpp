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
    for (int i = 0; i < n; ++i)
    {
        cout << n + 1 - a[i] << " ";
    }
    cout << endl;
    return;
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