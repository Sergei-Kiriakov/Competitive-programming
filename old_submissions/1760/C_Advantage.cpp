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
    int max1 = -1, max2 = -1;
    int ind1 = -1, ind2 = -1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > max1)
        {
            max2 = max1;
            ind2 = ind1;
            max1 = a[i];
            ind1 = i;
        }
        else if (a[i] > max2)
        {
            max2 = a[i];
            ind2 = i;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (ind1 != i)
        {
            cout << a[i] - max1 << " ";
        }
        else
        {
            cout << a[i] - max2 << " ";
        }
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