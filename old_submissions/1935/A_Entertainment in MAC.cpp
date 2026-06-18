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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    if (n % 2 == 1)
    {
        if (rev_s < s)
        {
            cout << rev_s << endl;
        }
        else
        {
            cout << s + rev_s << endl;
        }
    }
    else
    {
        if (rev_s < s)
        {
            cout << rev_s + s << endl;
        }
        else
        {
            cout << s << endl;
        }
    }
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