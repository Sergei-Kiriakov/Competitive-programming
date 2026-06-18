#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 998244353;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b > d)
    {
        cout << -1 << endl;
        return;
    }
    int dif = d - b;
    b += dif;
    a += dif;
    if (a < c)
    {
        cout << -1 << endl;
        return;
    }
    cout << dif + a - c << endl;
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