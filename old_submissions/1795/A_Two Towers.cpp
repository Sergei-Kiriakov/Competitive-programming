#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = m - 1; i > -1; --i)
    {
        s1.push_back(s2[i]);
    }
    int cnt = 0;
    for (int i = 1; i < n + m; ++i)
    {
        if (s1[i] == s1[i - 1])
        {
            ++cnt;
        }
    }
    if (cnt > 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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
