#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 998244353;

void solve()
{
    int a, b;
    cin >> a >> b;
    int ans = min(abs(a), abs(b));
    cout << ans * 2 +  max(abs(abs(a) - abs(b)) * 2 - 1, 0ll) << endl;
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
5
1 5
2 7
3 3
4 10
2 5
*/