#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b = {a[0]};
    int ans = 0;
    for(int i = 1; i < n; ++i)
    {
        if (a[i] == a[i - 1])
        {
            ans += c;
        }
        else
        {
            b.push_back(a[i]);
        }
    }
    if (b.size() == 0)
    {
        cout << ans + d << endl;
        return;
    }
    int ans1 = c * b.size() + d;
    n = b.size();
    for (int i = 0; i < b.size(); ++i)
    {
        ans1 = min(ans1, (n - i - 1) * c + (b[i] - i - 1) * d);
    }
    cout << ans + ans1 << endl;
}

int32_t main()
{
    // ofstream cout("sum.out");
    // ifstream cin("sum.in");
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