//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    int a = 1, b = 2, c = 3;
    n -= 6;
    if (n <= 0)
    {
        cout << "NO" << endl;
        return;
    }
    if (n % 3 == 0)
    {
        if (n == 3)
        {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        cout << a << " " << b + 2 << " " << c + n - 2 << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << a << " " << b << " " << c + n << endl;
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
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/