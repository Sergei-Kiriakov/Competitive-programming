//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93, ddl = 179;

int f(int m, int i, int j)
{
    return i * m + j + 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int d = 1;
    string ans = "YES";
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i - 1])
        {
            ans = "NO";
            break;
        }
        int dif = abs(a[i] - a[i - 1]);
        if (dif != 1 and dif != d)
        {
            if (d == 1)
                d = dif;
            else
                ans = "NO";
        }
    }
    if (d != 1)
    {
        int x = (a[0] - 1) / d, y = (a[0] - 1) % d;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] - a[i - 1] == 1) ++y;
            else if (a[i] - a[i - 1] == -1) --y;
            else if (a[i] - a[i - 1] == -d) --x;
            else ++x;
            if (a[i] != f(d, x, y) or y >= d or y < 0 or x < 0)
                ans = "NO";
        }
    }
    if (ans == "NO")
    {
        cout << ans << endl;
        return;
    }
    cout << ans << endl;
    cout << (int) 1e9 << " " << d << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(0);
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