#include <bits/stdc++.h>

#define Please return
#define Accepted 0
#define int long long
#define endl "\n"
#define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod1 = 1e9 + 9, d = 179, mod2 = 1e9 + 7;


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        a.push_back(k);
    }
    for (int i = 0; i < m; ++i)
    {
        int k;
        cin >> k;
        b.push_back(k);
        a.push_back(k);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int ans = 0;
    if (b[m - 1] < a[n - 1])
    {
        a[n - 1] = b[m - 1];
    }  
    for (int i = 0; i < n; ++i)
    {
        ans += a[i];
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}

/*
No brain
*/
