#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

constexpr int MAXN = 10, mod = 998244353;

void solve ()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (n == 2)
    {
        cout << 1 << " " << 3 << endl;
        return;
    }
    if (n % 2 == 1)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n - 2; ++i)
    {
        cout << 2 << " ";
    }
    cout << 1 << " " << 3 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }  
}

/*
1011
1001
*/