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
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i + 4 < n and s[i] == 'm' and s[i + 1] == 'a' and s[i + 2] == 'p' and s[i + 3] == 'i' and s[i + 4] == 'e')
        {
            ++ans;
            i = i + 4;
        }
        else if (i + 2 < n and s[i] == 'm' and s[i + 1] == 'a' and s[i + 2] == 'p')
        {
            i = i + 2;
            ++ans;
        }
        else if (i + 2 < n and s[i] == 'p' and s[i + 1] == 'i' and s[i + 2] == 'e')
        {
            i = i + 2;
            ++ans;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
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