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
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int min1 = 1e10, cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (min1 > a[i])
        {
            min1 = a[i];
            cnt = 1;
        }
        else if (min1 == a[i])
            ++cnt;
    }
    if (cnt == n)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << cnt << " " << n - cnt << endl;
        for (int i = 0; i < cnt; ++i)
        {
            cout << min1 << " ";
        }
        cout << endl;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != min1)
                cout << a[i] << " ";
        }
        cout << endl;
    }
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