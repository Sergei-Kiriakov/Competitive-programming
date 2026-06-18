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
vector<vector<int> > a;

void solve()
{
    int n;
    cin >> n;
    a.clear();
    anss.clear();
    a = vector<vector<int> > (n, vector<int> (n, 0));
    anss.push_back({1, n});
    for (int i = 0; i < n; ++i)
    {
        a[n - 1][i] = i + 1;
        anss.back().push_back(i + 1);
    }
    for (int ii = 0; ii < 2 * n - 2; ++ii)
    {
        if (ii % 2 == 0)
        {
            anss.push_back({1, n - ii / 2 - 1});
            for (int i = 0; i < n; ++i)
            {
                a[n - ii / 2 - 2][i] = i + 1;
                anss.back().push_back(i + 1);
            }
        }
        else
        {
            anss.push_back({2, n - ii / 2 - 1});
            for (int i = 0; i < n; ++i)
            {
                a[i][n - ii / 2 - 2] = i + 1;
                anss.back().push_back(i + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            ans += a[i][j];
//            cout << a[i][j] << " ";
        }
//        cout << endl;
    }
    cout << ans << " " << anss.size() << endl;
    for (int i = 0; i < anss.size(); ++i)
    {
        for (int j = 0; j < anss[i].size(); ++j)
        {
            cout << anss[i][j] << " ";
        }
        cout << endl;
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
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/