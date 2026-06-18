#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > ot;
    int cnt_beg = 0, cnt_end = 0;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (x == k)
        {
            ++cnt_beg;
        }
        if (y == k)
        {
            ++cnt_end;
        }
    }
    if (cnt_beg > 0 && cnt_end > 0)
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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
