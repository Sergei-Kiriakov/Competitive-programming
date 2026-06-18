#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 998244353;

void solve()
{
    int n, x, p;
    cin >> n >> x >> p;
    bool ans = false;
    for (int k = 1; k <= min(5 * n, p); ++k)
    {
        if ((k * (k + 1) / 2 + x) % n == 0)
        {
            ans = true;
        }
    }
    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
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
9 10 2 2
0 1 2 3 4 5 6 7 8
*/