#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].first %= k;
        if (a[i].first == 0)
            a[i].first = k;
        a[i].second = -i;
    }
    sort(all(a));
    for (int i = n - 1; i > -1; --i)
    {
        cout << -a[i].second + 1 << " ";
    }
    cout << endl;
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
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/