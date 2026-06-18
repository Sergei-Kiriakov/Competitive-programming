#include <bits/stdc++.h>

#define int long long

using namespace std;

constexpr int mod = 998244353;

void solve()
{
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    if (a[2] > 2 * (a[1] + a[0]))
    {
        cout << a[1] + a[0] << endl;
    }
    else
    {
        cout << (a[2] + a[1] + a[0]) / 3 << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
}

/*

*/