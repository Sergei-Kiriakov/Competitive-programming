//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

//#define int long long
//#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod1 = 1e9 + 7, mod2 = 1e9 + 9;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), cnt(2 * 1e5, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++cnt[a[i]];
    }
    int mex = 0;
    while (cnt[mex] != 0)
        ++mex;
    if (mex == 0)
    {
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 2 << " " << n << endl;
        return;
    }
    int mexx = 0;
    int i = 0;
    set<int> s;
    while (mexx < mex and i < n)
    {
        s.insert(a[i]);
        while (s.count(mexx))
            ++mexx;
        ++i;
    }
    int r = i;
    int mex1 = 0;
    set<int> s1;
    while (i < n)
    {
        s1.insert(a[i]);
        while (s1.count(mex1))
            ++mex1;
        ++i;
    }
    if (mexx != mex1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << 2 << endl;
        cout << 1 << " " <<  r << endl;
        cout << r + 1 << " " << n << endl;
    }
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
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