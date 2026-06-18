// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

void solve()
{
    int n;
    cin >> n;
    // test 3-4 : 5-8 (YES)
    // test 1: 1 (YES)
    // test 2: 15 (NO)
    if (n == 15 || n == 20 || n == 21)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}

int32_t main()
{
    // ofstream cout("sum.out");
    // ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // cout << fixed;
    // cout.precision(15);
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