//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93, ddl = 179;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];
    int i = 0, j = 0;
    int ans = 0;
    while (i < n and j < m)
    {
        int sum1 = a[i], sum2 = b[j];
        ++i;
        ++j;
        while (i < n and j < m and sum1 != sum2)
        {
            while (i < n and sum1 < sum2)
            {
                sum1 += a[i];
                ++i;
            }
            while (j < m and sum2 < sum1)
            {
                sum2 += b[j];
                ++j;
            }
        }
        if (sum1 != sum2)
        {
            while (i < n and sum1 < sum2)
            {
                sum1 += a[i];
                ++i;
            }
            while (j < m and sum2 < sum1)
            {
                sum2 += b[j];
                ++j;
            }
        }
        if (sum1 != sum2)
        {
            ans = -1;
            break;
        }
        else
            ++ans;
    }
    if (i == n and j == m)
        cout << ans << endl;
    else
        cout << -1 << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(0);
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