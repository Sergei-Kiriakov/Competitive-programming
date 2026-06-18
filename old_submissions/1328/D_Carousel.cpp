#include <bits/stdc++.h>

#define int long long

using namespace std;

constexpr int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    if (s.size() == 1)
    {
        cout << 1 << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }
    if (n % 2 == 0)
    {
        cout << 2 << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << i % 2 + 1 << " ";
        }
        cout << endl;
        return;
    }
    int ind = -1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == a[(i + 1) % n])
        {
            ind = i;
        }
    }
    if (ind != -1)
    {
        cout << 2 << endl;
        vector<int> ans(n);
        ans[ind] = 2;
        for (int i = 1; i < n; ++i)
        {
            ans[(ind + i) % n] = i % 2 + 1;
        }
        for (int i = 0; i < n; ++i)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    cout << 3 << endl;
    for (int i = 0; i < n - 1; ++i)
    {
        cout << i % 2 + 1 << " ";
    }
    cout << 3 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while (t--)
    {
        solve();
    }
}

/*

*/