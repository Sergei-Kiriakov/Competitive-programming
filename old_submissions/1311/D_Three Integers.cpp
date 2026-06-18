//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 7, ddl = 179;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 1e9;
    vector<int> anss(3, -1);
    for (int a1 = 1; a1 <= 2 * a; ++a1)
    {
        for (int b1 = a1; b1 <= 2 * b; b1 += a1)
        {
            int c1 = c / b1 * b1, c2 = c1 + b1;
            int d1 = abs(a1 - a) + abs(b1 - b) + abs(c1 - c);
            int d2 = abs(a1 - a) + abs(b1 - b) + abs(c2 - c);
            if (ans > d1 and c1 >= b1)
            {
                ans = d1;
                anss = {a1, b1, c1};
            }
            if (ans > d2 and c2 >= b1)
            {
                ans = d2;
                anss = {a1, b1, c2};
            }
        }
    }
    cout << ans << endl;
    cout << anss[0] << " " << anss[1] << " " << anss[2] << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(0);
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