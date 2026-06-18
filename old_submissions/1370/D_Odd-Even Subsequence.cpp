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

bool check(vector<int> &a, int k, int d)
{
    int n = a.size();
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (cnt0 % 2 == 0)
        {
            if (a[i] <= d)
                ++cnt0;
        }
        else
        {
            ++cnt0;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (cnt1 % 2 == 1)
        {
            if (a[i] <= d)
                ++cnt1;
        }
        else
        {
            ++cnt1;
        }
    }
    return cnt0 >= k or cnt1 >= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = 0, r = 1e9;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (check(a, k, mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(0);
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