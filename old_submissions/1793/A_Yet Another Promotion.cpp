#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 998244353;

void solve()
{
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    cout << min(n * b, n / (m + 1) * m * a + n % (m + 1) * min(a, b)) << endl;
}

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // solve();
    return 0;
}

/*
1
2
11
10
*/