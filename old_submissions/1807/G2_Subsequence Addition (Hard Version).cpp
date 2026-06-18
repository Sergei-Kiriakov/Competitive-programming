#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] != 1)
    {
        cout << "NO" << endl;
        return;
    }
    int sum = 1;
    bool ans = true;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > sum)
        {
            ans = false;
        }
        sum += a[i];
    }
    if (ans)
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
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    int tt = 1;
    cin >> tt;
    while (tt-->0)
    {
        solve();
    }
}


/*
5 4
1 2
2 3
3 4
4 5
*/