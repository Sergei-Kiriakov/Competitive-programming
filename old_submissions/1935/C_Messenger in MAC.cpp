//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod1 = 1e9 + 7, mod2 = 1e9 + 9;

void solve()
{
    int n, l;
    cin >> n >> l;
    vector<vector<int> > c(n, vector<int> (2));
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i][0] >> c[i][1];
        swap(c[i][0], c[i][1]);
//        c[i][1] = c[i][1];
    }
    sort(c.begin(), c.end());
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        multiset<int> s;
        int now = 0;
        for (int j = i; j < n; ++j)
        {
            int dif = c[j][0] - c[i][0];
            int t = l - dif;
            s.insert(c[j][1]);
            now += c[j][1];
            while (now > t and !s.empty())
            {
                now -= *(--s.end());
                s.erase((--s.end()));
            }
            ans = max(ans, (int) s.size());
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