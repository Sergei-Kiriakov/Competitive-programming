#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;


const int mod = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    if (s == "()")
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    bool flag = false;
    int i = 0;
    while (i < n && s[i] == '(')
        ++i;
    while (i < n && s[i] == ')')
        ++i;
    if (i != n)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << "(";
        }
        for (int i = 0; i < n; ++i)
        {
            cout << ")";
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            cout << "()";
        }
        cout << endl;
    }
}

int32_t main()
{
    //ofstream cout("sum.out");
    //ifstream cin("sum.in");
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