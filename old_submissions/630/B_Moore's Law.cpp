//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

int mod = 1e9 + 9;

double bin_pow(double a, int n)
{
    double ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans * a;
        a *= a;
        n >>= 1;
    }
    return ans;
}

void solve()
{
    int n, t;
    cin >> n >> t;
    double d = 1.000000011;
    cout << n * bin_pow(d, t) << endl;
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