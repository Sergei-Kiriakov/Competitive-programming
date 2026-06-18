#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

int d(int a, int b, int n)
{
    return (a - b) * (n - 1) + a;
}

int d1(int a, int b, int l)
{
    if (a >= l)
    {
        return 1;
    }
    return (l - a + (a - b - 1)) / (a - b) + 1;
}

void solve()
{
    int q;
    cin >> q;
    int l = 1, r = 1e18;
    for (int i = 0; i < q; ++i)
    {
        int f;
        cin >> f;
        if (f == 1)
        {
            int a, b, n;
            cin >> a >> b >> n;
            int r1 = d(a, b, n), l1;
            if (n == 1)
                l1 = 1;
            else
                l1 = (a - b) * (n - 2) + a + 1;
            if (max(l1, l) > min(r, r1))
            {
                cout << 0 << " ";
            }
            else
            {
                cout << 1 << " ";
                l = max(l, l1);
                r = min(r, r1);
            }
        }
        else
        {
            int a, b;
            cin >> a >> b;
            if (d1(a, b, l) != d1(a, b, r))
            {
                cout << -1 << " ";
            }
            else
            {
                cout << d1(a, b, l) << " ";
            }
        }
    }
    cout << endl;
}

int32_t main()
{
    // ofstream cout("sum.out");
    // ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }  
}


/*
1
3
1 3 2 5
2 4 1
2 3 2
*/  