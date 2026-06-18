//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

//#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define remin(x, y) x = min(x, y)
#define remax(x, y) x = max(x, y)
#define lowpos(a, x) int(lower_bound(a.begin(), a.end(), x) - a.begin())
#define uppos(a, x) int(upper_bound(a.begin(), a.end(), x) - a.begin())

using namespace std;

constexpr int mod = 998244353;

vector<vector<int> > anss;

void fill (int l, int r)
{
    if (l == r)
    {
        return;
    }
    fill(l, r - 1);
    anss.push_back({l, r});
    for (int i = l; i < r; ++i)
    {
        anss.push_back({i, i});
    }
    fill(l, r - 1);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int max1 = 0, max_mask = 0;
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        vector<int> d;
        int mmask = mask;
        for (int i = 0; i < n; ++i)
        {
            d.push_back(mmask % 2);
            mmask >>= 1;
        }
        int lenn = 0;
        int now = 0;
        for (int i = 0; i < n; ++i)
        {
            if (d[i] == 0)
            {
                ++lenn;
            }
            else
            {
                now += lenn * lenn;
                now += a[i];
                lenn = 0;
            }
        }
        now += lenn * lenn;
        lenn = 0;
        if (now > max1)
        {
            max1 = now;
            max_mask = mask;
        }
    }
    vector<int> d;
    for (int i = 0; i < n; ++i)
    {
        d.push_back(max_mask % 2);
        max_mask >>= 1;
    }
    int lenn = 0;
    for (int i = 0; i < n; ++i)
    {
        if (d[i] == 0)
        {
            ++lenn;
        }
        else
        {
            if (lenn != 0)
            {
                for (int j = i - lenn; j < i; ++j)
                {
                    if (a[j] != 0)
                        anss.push_back({j, j});
                }
                fill(i - lenn, i - 1);
                anss.push_back({i - lenn, i - 1});
            }
            lenn = 0;
        }
    }
    if (lenn != 0)
    {
        for (int j = n - lenn; j < n; ++j)
        {
            if (a[j] != 0)
                anss.push_back({j, j});
        }
        fill(n - lenn, n - 1);
        anss.push_back({n - lenn, n - 1});
    }
    cout << max1 << " " << anss.size() << endl;
    for (int i = 0; i < anss.size(); ++i)
    {
        cout << anss[i][0] + 1 << " " << anss[i][1] + 1 << endl;
    }
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
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