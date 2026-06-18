#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 998244353;

void solve()
{
    int n, k, d, w;
    cin >> n >> k >> d >> w;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int last = 0;
    int start = 0;
    for (int i = 0; i < n; ++i)
    {
        if (last == 0 || a[i] - start > d)
        {
            ++ans;
            last = k;
            start = a[i] + w;
        }
        --last;
    }
    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cerr.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    int tt = 1;
    cin >> tt;
    while (tt-->0)
    {
        solve();
    }
    return 0;
}


/*
1
9 10 2 2
0 1 2 3 4 5 6 7 8
*/