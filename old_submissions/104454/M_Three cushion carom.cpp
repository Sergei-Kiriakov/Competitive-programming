//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

int mod = 1e9 + 9;

int len(int x1, int y1, int xn, int yn)
{
    int dx = abs(xn - x1), dy = abs(yn - y1);
    return dx * dx + dy * dy;
}

void solve()
{
    int l, w;
    int x1, y1, x2, y2;
    cin >> l >> w;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = 1e10;
    for (int i = 0; i <= 3; ++i)
    {
        int j = 3 - i;
        {
            if (x1 == x2 and j == 3)
                continue;
            int xn = (i % 2 == 0 ? 0 : (l - x2) * 2) + x2 + l * (i - i % 2), yn = (j % 2 == 0 ? 0 : (w - y2) * 2) + y2 + w * (j - j % 2);
            ans = min(len(x1, y1, xn, yn), ans);
        }
        {
            if (x1 == x2 and j == 3)
                continue;
            int xn = (i % 2 == 0 ? 0 : (l - x2) * 2) + x2 + l * (i - i % 2), yn = (j % 2 == 0 ? 1 : -1) * y2 - w * (j - j % 2);
            ans = min(len(x1, y1, xn, yn), ans);
        }
        {
            if (y1 == y2 and i == 3)
                continue;
            int xn = (i % 2 == 0 ? 1 : -1) * x2 - l * (i - i % 2), yn = (j % 2 == 0 ? 0 : (w - y2) * 2) + y2 + w * (j - j % 2);
            ans = min(len(x1, y1, xn, yn), ans);
        }
        {
            if (y1 == y2 and i == 3)
                continue;
            int xn = (i % 2 == 0 ? 1 : -1) * x2 - l * (i - i % 2), yn = (j % 2 == 0 ? 1 : -1) * y2 - w * (j - j % 2);
            ans = min(len(x1, y1, xn, yn), ans);
        }
    }
    cout << sqrtl(ans) << endl;
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