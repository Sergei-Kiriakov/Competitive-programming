#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

constexpr int MAXN = 10, mod = 998244353;

void solve ()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> b;
    b.push_back(a[0]);
    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[i - 1])
        {
            b.push_back(a[i]);
        }
    }
    int cnt = 0;
    for (int i = 0; i < b.size(); ++i)
    {
        if (i == 0)
        {
            if (i + 1 < b.size())
            {
                if (b[i + 1] > b[i])
                {
                    ++cnt;
                }
            }
            else
            {
                ++cnt;
            }
        }
        else if (i + 1 == b.size())
        {
            if (b[i - 1] > b[i])
            {
                ++cnt;
            }
        }
        else
        {
            if (b[i - 1] > b[i] && b[i + 1] > b[i])
            {
                ++cnt;
            }
        }
    }
    if (cnt == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }  
}

/*
*/