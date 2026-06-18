#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;



int check(int m, vector<int>& a, vector<int>& b)
{
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += abs(a[i] - b[i] * m);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    int k = b[0];
    for (int i = 1; i < n; ++i)
    {
        k = __gcd(k, b[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        b[i] /= k;
    }
    int l = 0, r = 1e9;
    while (r - l > 2)
    {
        int m = (r + l) / 2;
        if (check(m, a, b) <= check(m +1, a, b))
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    int ans = 1e18;
    for (int i = max(l, 1ll); i <= r; ++i)
    {
        ans = min(ans, check(i, a, b));
    }
    cout << ans << endl;
}

int32_t main()
{
    //ofstream cout("sum.out");
    //ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    //cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/