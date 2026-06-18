//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93, ddl = 179;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];

    if (k == 1)
    {
        string ans = "YES";
        for (int i = 0; i < n; ++i)
            if (b[i] != i + 1)
                ans = "NO";
        cout << ans << endl;
        return;
    }

    string ans = "YES";
    vector<int> times(n, -1);
    vector<int> col(n, -1);
    int now_col = 0;
    for (int i = 0; i < n; ++i)
    {
        if (col[i] == -1)
        {
            int ind = i;
            int tic = 0;
            while (col[ind] == -1)
            {
                col[ind] = now_col;
                times[ind] = tic++;
                ind = b[ind] - 1;
            }
            if (col[ind] == now_col and tic - times[ind] != k)
            {
                ans = "NO";
            }
            ++now_col;
        }
    }
    cout << ans << endl;
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