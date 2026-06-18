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
    string s1, s2;
    cin >> s1 >> s2;
    int ii = 0;
    int n = s1.size();
    while (ii < n and s1[ii] == s2[ii])
    {
        ++ii;
    }
    if (ii == n)
    {
        cout << s1 << endl;
        cout << s2 << endl;
        return;
    }
    bool flag = s1[ii] > s2[ii];
    for (int i = ii + 1; i < n; ++i)
    {
        if (flag)
        {
            if (s1[i] > s2[i])
            {
                swap(s1[i], s2[i]);
            }
        }
        else
        {
            if (s1[i] < s2[i])
            {
                swap(s1[i], s2[i]);
            }
        }
    }
    cout << s1 << endl;
    cout << s2 << endl;
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