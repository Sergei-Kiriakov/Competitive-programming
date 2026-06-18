//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 998244353, big = 2e6;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(2 * n + 10, vector<int> (2 * m + 10, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 2 * m; ++j)
        {
            int d;
            cin >> d;
            if (j % 2 == 0)
                a[i * 2][j + 1] = d;
            else
                a[i * 2 + 1][j - 1] = d;
        }
    }
//    for (int i = 0; i < 2 * n; ++i)
//    {
//        for (int j = 0; j < 2 * m; ++j)
//        {
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }
    a[1][1] = 0;
    for (int i = 1; i < 2 * n; i += 2)
    {
        for (int j = 1; j < 2 * m; j += 2)
        {
            if (i == 0 and j == 0)
                continue;
            a[i][j + 2] = a[i][j] + a[i][j + 1];
        }
        a[i + 2][1] = a[i][1] - a[i + 1][1];
    }
//    cout << endl;
//    for (int i = 0; i < 2 * n; ++i)
//    {
//        for (int j = 0; j < 2 * m; ++j)
//        {
//            cout << (a[i][j]) << " ";
//        }
//        cout << endl;
//    }
    bool ans = true;
    for (int i = 1; i < 2 * n; i += 2)
    {
        for (int j = 1; j < 2 * m; j += 2) {
            int i1 = (i + 2) % (2 * n), j1 = j;
            int i2 = (i - 2 + 2 * n) % (2 * n), j2 = j;
            int i3 = i, j3 = (j + 2) % (2 * m);
            int i4 = i, j4 = (j - 2 + 2 * m) % (2 * m);
            if (a[i][j] - a[i1][j1] != a[(i + 1) % (2 * n)][j]) {
                ans = false;
            }
            if (-a[i][j] + a[i2][j2] != a[i - 1][j]) {
                ans = false;
            }
            if (-a[i][j] + a[i3][j3] != a[i][(j + 1) % (2 * m)]) {
                ans = false;
            }
            if (a[i][j] - a[i4][j4] != a[i][j - 1]) {
                ans = false;
            }
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
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
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