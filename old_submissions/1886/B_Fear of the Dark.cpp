//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

int rast(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

void solve()
{
    pair<int, int> p;
    cin >> p.first >> p.second;
    pair<int, int> a;
    cin >> a.first >> a.second;
    pair<int, int> b;
    cin >> b.first >> b.second;
    double l = 0, r = 1e9;
    pair<int, int> z = {0, 0};
    while (r - l > 1e-7)
    {
        double mid1 = (r + l) / 2.;
//        double mid1 = 3.2015621187;
        double mid = mid1 * mid1;
        if ((rast(z, b) <= mid or rast(z, a) <= mid) and (rast(p, b) <= mid or rast(p, a) <= mid))
        {
            if ((rast(z, b) <= mid and (rast(p, b) <= mid)) or
                    (rast(z, a) <= mid and (rast(p, a) <= mid)))
            {
                r = mid1;
            }
            else
            {
                if (rast(a, b) <= 4 * mid)
                {
                    r = mid1;
                }
                else
                {
                    l = mid1;
                }
            }
        }
        else
        {
            l = mid1;
        }
    }
    cout << l << endl;
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
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/