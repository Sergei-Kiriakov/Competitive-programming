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
    vector<vector<int> > a(n, vector<int> (4));
    for (int i = 0; i < n; ++i)
    {
        int l, r, l1, r1;
        cin >> l >> r >> l1 >> r1;
        a[i][0] = l;
        a[i][1] = r;
        a[i][2] = l1;
        a[i][3] = r1;
    }
    int q;
    cin >> q;
    vector<pair<int, int> > x(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> x[i].first;
        x[i].second = i;
    }
    sort(all(a));
    sort(all(x));
    vector<int> ans(q);
    int start = -1;
    int ind = 0;
    for (int i = 0; i < q; ++i)
    {
        if (start >= x[i].first)
        {
            ans[x[i].second] = start;
            continue;
        }
        start = x[i].first;
        while (ind < n and start >= a[ind][0])
        {
            start = max(a[ind][3], start);
            ++ind;
        }
        ans[x[i].second] = start;
    }
    for (int i = 0; i < q; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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