//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

int bin_pow (int a, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

int inverse_mod (int a)
{
    return bin_pow(a, mod - 2);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int ans = 1;
    int cnt = n;
    bool z = (s[0] == '?');
    for (int i = n - 1; i > 0; --i)
    {
        if (s[i] == '?')
        {
            ans = ans * (n - 1) % mod;
        }
        --n;
    }
    if (z)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    for (int i = 0; i < m; ++i)
    {
        int ind;
        char c;
        cin >> ind >> c;
        --ind;
        if (ind == 0)
        {
            if (c != '?')
                z = false;
            else
                z = true;
        }
        else
        {
            if (s[ind] == '?' and c != '?')
                ans = ans * inverse_mod(ind) % mod;
            else if (s[ind] != '?' and c == '?')
                ans = ans * ind % mod;
        }
        s[ind] = c;
        if (z)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << ans << endl;
        }
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
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/