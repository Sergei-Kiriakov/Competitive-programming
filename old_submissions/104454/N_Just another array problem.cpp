//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 7, big = 2e6;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, pair<int, int> > dd;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (dd.count(a[i]))
            dd[a[i]].second = i;
        else
        {
            dd[a[i]].first = i;
            dd[a[i]].second = i;
        }
    }
    int q;
    cin >> q;
    int k = 0;
    for (int i = 0; i < q; ++i)
    {
        char c;
        cin >> c;
        if (c == '?')
        {
            int x;
            cin >> x;
            if (dd.count(x))
            {
                int l = dd[x].first + k, r = dd[x].second + k;
                if (l <= n and r >= n)
                {
                    cout << 1 << endl;
                }
                else
                {
                    cout << min(l % n, r % n) + 1 << endl;
                }
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
        {
            int kk;
            cin >> kk;
            k = (k + kk + n) % n;
        }
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
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/