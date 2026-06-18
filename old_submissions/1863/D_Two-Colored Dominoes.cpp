//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;


const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<vector<int> > b(n, vector<int> (m, 0));
    bool ans = true;
    for (int i = 0; i < n; ++i)
    {
        int last = 0;
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 'U')
            {
                if (last >= 0)
                {
                    b[i][j] = -1;
                    b[i + 1][j] = 1;
                    last = -1;
                }
                else
                {
                    b[i][j] = 1;
                    b[i + 1][j] = -1;
                    last = 1;
                }
            }
        }
    }
    for (int j = 0; j < m; ++j)
    {
        int last = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i][j] == 'L')
            {
                if (last >= 0)
                {
                    b[i][j] = -1;
                    b[i][j + 1] = 1;
                    last = -1;
                }
                else
                {
                    b[i][j] = 1;
                    b[i][j + 1] = -1;
                    last = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        int bal = 0;
        for (int j = 0; j < m; ++j)
        {
            bal += b[i][j];
        }
        if (bal != 0)
            ans = false;
    }
    for (int j = 0; j < m; ++j)
    {
        int bal = 0;
        for (int i = 0; i < n; ++i)
        {
            bal += b[i][j];
        }
        if (bal != 0)
            ans = false;
    }
    if (!ans)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (b[i][j] == 1)
            {
                cout << "W";
            }
            else if (b[i][j] == -1)
            {
                cout << "B";
            }
            else
            {
                cout << ".";
            }
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