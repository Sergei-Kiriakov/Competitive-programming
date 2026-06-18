//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n / 2; ++i)
    {
        if (s[i] != s[n - i - 1])
            ++cnt;
    }
    if (n % 2 == 1)
    {
        for (int i = 0; i < cnt; ++i) cout << "0";
        for (int i = cnt; i < n + 1 - cnt; ++i) cout << "1";
        for (int i = n + 1 - cnt; i < n + 1; ++i) cout << "0";
    }
    else
    {
        for (int i = 0; i < cnt; ++i) cout << "0";
        for (int i = cnt; i < n + 1 - cnt; ++i)
        {
            if ((cnt - i) % 2 == 0)
                cout << "1";
            else
                cout << "0";
        }
        for (int i = n + 1 - cnt; i < n + 1; ++i) cout << "0";
    }
    cout << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(0);
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