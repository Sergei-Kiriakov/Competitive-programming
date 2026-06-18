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
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int> (n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    bool exist0 = false;
    int pos_0_i = -1, pos_0_j = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] == 0)
            {
                pos_0_i = i;
                pos_0_j = j;
                exist0 = true;
            }

    vector<vector<int> > cnt2(n, vector<int> (n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            int now = a[i][j];
            while (now % 2 == 0 and now != 0)
            {
                now /= 2;
                ++cnt2[i][j];
            }
        }
    vector<vector<int> > cnt5(n, vector<int> (n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            int now = a[i][j];
            while (now % 5 == 0 and now != 0)
            {
                now /= 5;
                ++cnt5[i][j];
            }
        }

    vector<vector<int> > dp2(n, vector<int> (n, 1e9)), dp5(n, vector<int> (n, 1e9));
    dp2[0][0] = cnt2[0][0];
    dp5[0][0] = cnt5[0][0];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] == 0)
                continue;
            if (i == 0 and j == 0)
                continue;
            if (i == 0)
                dp2[i][j] = dp2[i][j - 1] + cnt2[i][j];
            else if (j == 0)
                dp2[i][j] = dp2[i - 1][j] + cnt2[i][j];
            else
                dp2[i][j] = min(dp2[i - 1][j], dp2[i][j - 1]) + cnt2[i][j];
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] == 0)
                continue;
            if (i == 0 and j == 0)
                continue;
            if (i == 0)
                dp5[i][j] = dp5[i][j - 1] + cnt5[i][j];
            else if (j == 0)
                dp5[i][j] = dp5[i - 1][j] + cnt5[i][j];
            else
                dp5[i][j] = min(dp5[i - 1][j], dp5[i][j - 1]) + cnt5[i][j];
        }


    int min1 = min(dp2[n - 1][n - 1], dp5[n - 1][n - 1]);
    if (exist0 and min1 > 1)
    {
        cout << 1 << endl;
        for (int i = 0; i < pos_0_i; ++i) cout << "D";
        for (int j = 0; j < pos_0_j; ++j) cout << "R";
        for (int i = pos_0_i; i < n - 1; ++i) cout << "D";
        for (int j = pos_0_j; j < n - 1; ++j) cout << "R";
        cout << endl;
    }
    else if (dp2[n - 1][n - 1] < dp5[n - 1][n - 1])
    {
        cout << dp2[n - 1][n - 1] << endl;
        string s;
        int i = n - 1, j = n - 1;
        while (i != 0 or j != 0)
        {
            if (i == 0)
            {
                --j;
                s.push_back('R');
            }
            else if (j == 0)
            {
                --i;
                s.push_back('D');
            }
            else
            {
                if (dp2[i - 1][j] < dp2[i][j - 1])
                {
                    --i;
                    s.push_back('D');
                }
                else
                {
                    --j;
                    s.push_back('R');
                }
            }
        }
        reverse(all(s));
        cout << s << endl;
    }
    else
    {
        cout << dp5[n - 1][n - 1] << endl;
        string s;
        int i = n - 1, j = n - 1;
        while (i != 0 or j != 0)
        {
            if (i == 0)
            {
                --j;
                s.push_back('R');
            }
            else if (j == 0)
            {
                --i;
                s.push_back('D');
            }
            else
            {
                if (dp5[i - 1][j] < dp5[i][j - 1])
                {
                    --i;
                    s.push_back('D');
                }
                else
                {
                    --j;
                    s.push_back('R');
                }
            }
        }
        reverse(all(s));
        cout << s << endl;
    }
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/