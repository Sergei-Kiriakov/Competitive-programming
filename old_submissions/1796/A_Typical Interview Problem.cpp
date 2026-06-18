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

string f(string s)
{
    string ans;
    int n = s.size();
    for (int i = 1; i < n; ++i)
    {
        ans.push_back(s[i]);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n; 
    string s;
    cin >> s;
    for (int i = 1; i < 20; ++i)
    {
        string ans;
        for (int j = 0; j < 50; ++j)
        {
            int k = i + j;
            if (k % 3 == 0)
            {
                ans.push_back('F');
            }
            if (ans == s || f(ans) == s)
            {
                cout << "YES" << endl;
                return;
            }
            if (k % 5 == 0)
            {
                ans.push_back('B');
            }
            if (ans == s || f(ans) == s)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

/*
...
*/