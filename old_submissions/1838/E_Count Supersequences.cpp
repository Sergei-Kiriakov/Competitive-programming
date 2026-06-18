//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 7, ddl = 179;

int bin_pow(int a, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = (ans * a) % mod;
        n >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

int inverse_mod(int a)
{
    return bin_pow(a, mod - 2);
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = bin_pow(k, m);
    ans = (ans + mod - bin_pow(k - 1, m)) % mod;
    vector<int> A(n + 1, 1);
    for (int i = 1; i < n + 1; ++i) A[i] = A[i - 1] * (m - i + 1) % mod * inverse_mod(i) % mod;
    for (int i = 1; i < n; ++i)
    {
        int cnt = A[i] * bin_pow(k - 1, m - i) % mod;
        ans = (ans + mod - cnt) % mod;
    }
    cout << ans << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(0);
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