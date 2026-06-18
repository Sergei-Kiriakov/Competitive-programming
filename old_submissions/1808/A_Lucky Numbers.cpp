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
    int l, r;
    cin >> l >> r;
    int ans = -1, cnt = 0;
    for (int i = l; i <= min(r, l + 200); ++i)
    {
        int d = f(i);
        if (d > ans)
        {
            ans = d;
            cnt = i;
        }
    }
    cout << cnt << endl;
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