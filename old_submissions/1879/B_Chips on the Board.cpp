//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

int mod = 1e9 + 9;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> c;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        c.push_back(a[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        c.push_back(b[i]);
    }
    sort(all(c));
    sort(all(a));
    sort(all(b));
    int ans1 = n * a[0], ans2 = b[0] * n;
    for (int i = 0; i < n; ++i)
    {
        ans1 += b[i];
        ans2 += a[i];
    }
    cout << min(ans1, ans2) << endl;
}

int32_t main()
{
//    ofstream cout("sum.out");
//    ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(9);
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