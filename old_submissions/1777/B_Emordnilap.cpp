#include <bits/stdc++.h>

#define int long long

using namespace std;

const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    int ans = 1;
    for (int i = 2; i <= n; ++i)
    {
        ans = (ans * i) % mod;
    }
    int k = n * (n - 1) % mod;
    cout << ans * k % mod << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
