//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define remin(x, y) x = min(x, y)
#define remax(x, y) x = max(x, y)
#define lowpos(a, x) int(lower_bound(a.begin(), a.end(), x) - a.begin())
#define uppos(a, x) int(upper_bound(a.begin(), a.end(), x) - a.begin())

using namespace std;

constexpr int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    vector<int> b = {a[0]};
    for (int i = 1; i < n; ++i)
        if (a[i] != a[i - 1])
            b.push_back(a[i]);
    n = b.size();
    vector<vector<bool> > pos(n, vector<bool> (2, true));
    for (int i = n - 2; i > -1; --i)
    {
        int dif;
        if (i == 0)
        {
            dif = b[0];
        }
        else
        {
            dif = b[i] - b[i - 1];
        }
        if (dif == 1)
        {
            pos[i][0] = !pos[i + 1][1];
            pos[i][1] = !pos[i + 1][1];
        }
        else
        {
            pos[i][0] = !pos[i + 1][1];
            pos[i][1] = (!pos[i + 1][1] or !pos[i][0]);
        }
    }
    if (pos[0][1])
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Bob" << endl;
    }
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
//    cout << fixed;
//    cout.precision(7);
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