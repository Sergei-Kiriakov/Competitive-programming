#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 998244353;

int bin_pow (int a, int n, int mod=mod)
{
    int ans = 1;
    a %= mod;
    while (n)
    {
        if (n & 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}
 
int div_mod (int a, int b, int mod=mod)
{
    return a * bin_pow(b, mod - 2) % mod;
}

int cnk (int n, int k, vector<int> &fact)
{
    return div_mod(div_mod(fact[n], fact[k]), fact[n - k]);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> fact(2 * n + 1, 1);
    for (int i = 2; i < 2 * n + 1; ++i)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    int ans = cnk(n / 3, n / 6, fact);
    // cout << ans << endl;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i += 3)
    {
        vector<int> b = {a[i], a[i + 1], a[i + 2]};
        sort(b.begin(), b.end());
        if (b[0] == b[1] && b[2] == b[1])
        {
            ans = ans * 3 % mod;
        }
        else if (b[0] == b[1])
        {
            ans = ans * 2 % mod;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}
