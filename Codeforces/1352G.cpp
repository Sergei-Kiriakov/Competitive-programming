#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod1 = 1e9 + 9, d = 179, mod2 = 1e9 + 7;

const double pi = 3.14159265358979323846;

void solve ()
{
    int n;
    cin >> n;
    if (n < 4)
    {
        cout << -1 << endl;
        return;
    }
    if (n % 2 == 1)
    {
        for (int i = 1; i <= n; i += 2)
        {
            cout << i << " ";
        }
        --n;
        for (int i = n; i > 0; i -= 2)
        {
            if (i == n)
            {
                cout << n - 2 << " ";
            }
            else if (i == n - 2)
            {
                cout << n << " ";
            }
            else
            {
                cout << i << " ";
            }
        }
        return;
    }
    for (int i = 1; i <= n; i += 2)
    {
        if (i == n - 3)
        {
            cout << n - 1 << " ";
        }
        else if (i == n - 1)
        {
            cout << n - 3 << " ";
        }
        else 
        {
            cout << i << " ";
        }
    }
    for (int i = n; i > 0; i -= 2)
    {
        cout << i << " ";
    }
    cout << endl;
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