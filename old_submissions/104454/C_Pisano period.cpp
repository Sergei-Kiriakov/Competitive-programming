//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

int mod = 1e9 + 9;

class Matrix
{
public:
    vector<int> a;

    Matrix ()
    {
        a = {0, 1, 1, 1};
    }
    Matrix (vector<int> b)
    {
        a = {b[0], b[1], b[2], b[3]};
    }
    Matrix (int b)
    {
        a = {b, b, b, b};
    }

    Matrix operator*(Matrix B)
    {
        Matrix c;
        c.a[0] = (a[0] * B.a[0] + a[1] * B.a[2]) % mod;
        c.a[1] = (a[0] * B.a[1] + a[1] * B.a[3]) % mod;
        c.a[2] = (a[2] * B.a[0] + a[3] * B.a[2]) % mod;
        c.a[3] = (a[2] * B.a[1] + a[3] * B.a[3]) % mod;
        return c;
    }
};

Matrix bin_pow(Matrix a, int n)
{
    Matrix ans(1);
    while(n)
    {
        if (n & 1)
            ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}

int fib (int n)
{
    Matrix a;
    int ans = bin_pow(a, n - 1).a[2];
    return ans;
}

void solve()
{
    int p;
    cin >> p;
    if (p == 2)
    {
        cout << 3 << endl;
        return;
    }
    if (p == 5)
    {
        cout << 20 << endl;
        return;
    }
    int d = 2 * (p + 1);
    if (p % 5 == 1 or p % 5 == 4)
        d = p - 1;
    int ans = 1e10;
    mod = p;
    for (int i = 1; i * i <= d; ++i)
    {
        if (d % i == 0)
        {
            if (fib(i) == 0 and fib(i + 1) == 1)
                ans = min(ans, i);
        }
        int kk = d / i;
        if (d % kk == 0)
        {
            if (fib(kk) == 0 and fib(kk + 1) == 1)
                ans = min(ans, kk);
        }
    }
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