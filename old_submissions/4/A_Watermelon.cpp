//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

vector<int> fac;

void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0 and n > 3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int32_t main()
{
    int big = 1e6;
    fac = vector<int> (big, 1);
    for (int i = 2; i < big; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
//    ofstream cout("sum.out");
//    ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(9);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    // cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/  