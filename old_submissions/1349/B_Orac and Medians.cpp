//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 998244353, d = 179;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        cnt += a[i] == k;
    }
    if (cnt == 0)
    {
        cout << "no" << endl;
        return;
    }
    if (n == 1)
    {
        cout << "yes" << endl;
        return;
    }
    string ans = "no";
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n and j - i <= 2; ++j)
            if (a[i] >= k and a[j] >= k)
                ans = "yes";
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