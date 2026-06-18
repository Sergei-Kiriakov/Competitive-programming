#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        string s;
        cin >> s;
        int n = s.size(), bal = 0, ans = 0, min1 = 0;
        for (int j = 0; j < n; ++j)
        {
            if (s[j] == '+')
                ++bal;
            else
                --bal;
            if (bal < min1)
            {
                min1 = bal;
                ans += j + 1;
            }
        }
        cout << ans + n << "\n";
    }
}
