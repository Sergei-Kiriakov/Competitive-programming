//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

int mod = 1e9 + 9;

void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx = abs(x2 - x1) + 1, dy = abs(y2 - y1);
    int d1 = dx / 2 + dx % 2;
    int d2 = dx / 2;
    int ans = dx * dy / 2;
    if (dy % 2 == 0)
        ans += d1;
    else
        ans += d2;
    cout << ans << endl;

}

int32_t main()
{
//    ofstream cout("sum.out");
//    ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
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