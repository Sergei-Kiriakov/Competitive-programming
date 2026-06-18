#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, mod = 1e9 + 7;
    cin >> k;
    int l = 1, r = 50;
    while (r - l > 1)
    {
        int m = (l + r) / 2, c = m * m * m * m * m * m * m * m * m * m;
        if (c < k)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    vector<int> a(10, l);
    int c = l * l * l * l * l * l * l * l * l * l, i = 0;
    while (i < 10 && c < k)
    {
        c /= l;
        c *= r;
        a[i] += 1;
        ++i;
    }
    string s = "codeforces";
    vector<char> ans;
    for(int j = 0; j < 10; ++j)
    {
        for(int h = 0; h < a[j]; ++h)
        {
            cout << (s[j]);
        }
    }
    cout << "\n";
}
