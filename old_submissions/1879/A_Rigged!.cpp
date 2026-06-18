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
    vector<vector<int> > a(n, vector<int> (2));
    for (int i = 0; i < n; ++i)
        cin >> a[i][0] >> a[i][1];
    int d = a[0][0];
    int cnt = a[0][1];
    bool ans = true;
    for (int i = 1; i < n; ++i)
    {
        if (a[i][0] >= d and a[i][1] >= cnt)
            ans = false;
    }
    if (ans)
    {
        cout << d << endl;
    }
    else
    {
        cout << -1 << endl;
    }
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