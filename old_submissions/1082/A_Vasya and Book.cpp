//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;


const int mod = 1e9 + 7;

void solve()
{
    int n, x, y, d;
    cin >> n >> x >> y >> d;
    if (abs(y - x) % d != 0)
    {
        int dd = 1e10;
        if ((y - 1) % d == 0)
        {
            dd = min(dd, (y - 1) / d + (x - 1 + d - 1) / d);
        }
        if ((n - y) % d == 0)
        {
            dd = min(dd, (n - y) / d + (n - x + d - 1) / d);
        }
        if (dd == 1e10)
        {
            cout << -1 << endl;
            return;
        }
        cout << dd << endl;
        return;
    }
    cout << (abs(y - x) / d) << endl;
}

int32_t main()
{
    //ofstream cout("sum.out");
    //ifstream cin("sum.in");
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
*/