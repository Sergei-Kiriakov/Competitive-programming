#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 998244353;

void solve();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cerr.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1[0] == s2[0])
    {
        cout << "YES" << endl;
        cout << s1[0] << '*' << endl;
        return;
    }
    if (s1.back() == s2.back())
    {
        cout << "YES" << endl;
        cout << '*' << s1.back() << endl;
        return;
    }
    int n = s1.size(), m = s2.size();
    for (int i = 1; i < n; ++i)
    {
        pair<char, char> g = {s1[i - 1], s1[i]};
        for (int j = 1; j < m; ++j)
        {
            pair<char, char> k = {s2[j - 1], s2[j]};
            if (k == g)
            {
                cout << "YES" << endl;
                cout << '*' << k.first << k.second << '*' << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

/*
1
codeforces
atcoder
*/