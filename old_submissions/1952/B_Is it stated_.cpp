//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353, mod2 = 1e9 + 9;

void solve ()
{
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == 'i' and s[i + 1] == 't')
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
    vector<string> a;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/