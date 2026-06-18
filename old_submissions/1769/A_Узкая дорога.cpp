#include <bits/stdc++.h>

#define Please return
#define Accepted 0
#define int long long
#define endl "\n"

using namespace std;

constexpr int MAXN = 10, mod = 998244353;

void solve ()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    --a[0];
    for (int i = 1; i < n; ++i)
    {
        a[i] = max(a[i] - i - 1, a[i - 1] + 1);
    }
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt;
    // cin >> tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }
}

/*
0 1
4
1 2 2 5
1 2 3 5
*/
