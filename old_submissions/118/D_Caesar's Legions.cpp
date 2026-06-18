#include <bits/stdc++.h>

#define Please return
#define Accepted 0
#define int long long
#define endl "\n"
#define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod = 1e8;

void solve ()
{
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    vector<vector<int> > sol(n1 + 1, vector<int> (n2 + 1, 0)), cav(n1 + 1, vector<int> (n2 + 1, 0));
    sol[0][0] = 1;
    cav[0][0] = 1;
    for (int x1 = 0; x1 <= n1; ++x1)
    {
        for (int x2 = 0; x2 <= n2; ++x2)
        {
            for (int i = 1; i + x1 <= n1 && i <= k1; ++i)
            {
                sol[x1 + i][x2] = (sol[x1 + i][x2] + cav[x1][x2]) % mod;
            }
            for (int i = 1; i + x2 <= n2 && i <= k2; ++i)
            {
                cav[x1][x2 + i] = (cav[x1][x2 + i] + sol[x1][x2]) % mod;
            }
        }
    }
    cout << (cav[n1][n2] + sol[n1][n2]) % mod << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
}

/*
0 1
4
1 2 2 5
1 2 3 5
3 2 2 1 1 
*/
