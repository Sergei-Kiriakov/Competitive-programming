//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

void solve()
{
    int n, p, w, d;
    cin >> n >> p >> w >> d;
    int big = n * w;
    if (big < p)
    {
        cout << -1 << endl;
        return;
    }
    int cnt1 = p / w;
    int x = -1, y = -1, z = -1;
    for (int i = 0; i <= d; ++i)
    {
        if (cnt1 < 0)
            break;
        if ((p - cnt1 * w) % d == 0)
        {
            int cnt2 = (p - cnt1 * w) / d;
            if (cnt1 + cnt2 <= n)
            {
                x = cnt1;
                y = cnt2;
                z = n - cnt1 - cnt2;
            }
        }
        --cnt1;
    }
    if (x == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << x << " " << y << " " << z << endl;
    }
}

int32_t main()
{
//    ofstream cout("sum.out");
//    ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(9);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/  