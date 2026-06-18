#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 998244353;

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
    int l = 0, r = n - 1;
    while (r > l && (a[l] == *s.begin() || a[l] == *(--s.end()) || a[r] == *s.begin() || a[r] == *(--s.end())))
    {
        while (r > l && (a[l] == *s.begin() || a[l] == *(--s.end())))
        {
            s.erase(a[l]);
            ++l;
        }
        while (r > l && (a[r] == *s.begin() || a[r] == *(--s.end())))
        {
            s.erase(a[r]);
            --r;
        }
    }
    pair<int, int> ans = {-1, -1};
    if (l != n && r > -1 && l != r)
    {
        ans = {l, r};
    }
    if (ans.first == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans.first + 1 << " " << ans.second + 1 << endl;
    }
}

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // solve();
    return 0;
}

/*
1
2
11
10
*/