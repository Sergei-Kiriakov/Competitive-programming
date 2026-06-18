#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 7, ddl = 179;

void solve()
{
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];
    int k;
    cin >> k;
    vector<vector<int> > d;
    for (int i = 0; i < n; ++i)
    {
        d.push_back({k / c[i], i});
    }
    sort(all(d));
    vector<int> inds, dds;
    int dd = d.back()[0], ind = d.back()[1];
    inds.push_back(ind);
    dds.push_back(dd);
    while (k != 0 and inds.back() != -1 and dds.back() > 0)
    {
        ind = inds.back();
        k %= c[ind];
        for (int i = ind + 1; i < n; ++i)
        {
            c[i] -= c[ind];
        }
        int ind2 = -1;
        int l = -1;
        for (int i = ind + 1; i < n; ++i)
        {
            if (k >= c[i] and k / c[i] >= l)
            {
                ind2 = i;
                l = k / c[i];
            }
        }
        dds.push_back(l);
        inds.push_back(ind2);
    }
    if (inds.back() == -1 or dds.back() == 0)
    {
        inds.pop_back();
        dds.pop_back();
    }
    int ll = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ll < inds.size() and i < inds[ll])
        {
            cout << dds[ll] << " ";
        }
        else if (ll < inds.size() and i == inds[ll])
        {
            cout << dds[ll] << " ";
            ++ll;
        }
        else
            cout << 0 << " ";
    }
    cout << endl;
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