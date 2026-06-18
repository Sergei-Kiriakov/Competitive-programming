#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

constexpr int MAXN = 10, mod = 998244353;

void solve ()
{
    string s;
    cin >> s;
    int n = s.size();
    string ans = s + s;
    for (int i = 0; i < n; ++i)
    {
        ans[2 * n - 1 - i] = s[i];
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
*/