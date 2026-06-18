//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;


const int mod = 1e9 + 7;

void solve()
{
    int n, a, q;
    cin >> n >> a >> q;
    string s;
    cin >> s;
    int bal = a, sum = a;
    for (int i = 0; i < q; ++i)
    {
        if (bal >= n)
        {
            cout << "YES" << endl;
            return;
        }
        if (s[i] == '+')
        {
            ++bal;
            ++sum;
        }
        else
        {
            --bal;
        }
    }
    if (bal >= n)
    {
        cout << "YES" << endl;
        return;
    }
    if (sum >= n)
    {
        cout << "MAYBE" << endl;
    }
    else
    {
        cout << "NO" << endl;
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