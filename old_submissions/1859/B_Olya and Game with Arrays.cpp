//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int> > a(n, {1e10, 1e10});
    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j)
        {
            int temp;
            cin >> temp;
            if (a[i].first > temp)
            {
                a[i].second = a[i].first;
                a[i].first = temp;
            }
            else if (a[i].second > temp)
            {
                a[i].second = temp;
            }
        }
    }
    sort(all(a));
    int min1 = a[0].first;
    int delta = 1e10, ind = -1;
    for (int i = 0; i < n; ++i)
    {
        if (delta > a[i].second - min1)
        {
            delta = a[i].second - min1;
            ind = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ind != i)
            ans += a[i].second;
        else
            ans += min1;
    }
    cout << ans << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
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