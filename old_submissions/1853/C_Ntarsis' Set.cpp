//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    if (a[0] != 1)
    {
        cout << 1 << endl;
        return;
    }
    int l = 0, r = n * k + 1;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        int cnt = 0;
        int mid1 = mid;
        for (int i = 0; i < k; ++i)
        {
            int c = (int) (upper_bound(all(a), mid1) - a.begin());
            cnt += c;
            mid1 -= c;
        }
        if (cnt == mid)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << r << endl;
}

int32_t main()
{
    //ofstream cout("sum.out");
    //ifstream cin("sum.in");
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