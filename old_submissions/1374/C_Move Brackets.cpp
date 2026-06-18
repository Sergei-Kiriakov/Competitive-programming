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
        int n, ans = 0, bal = 0;
        string s;
        cin >> n >> s;
        for (int j = 0; j < n; ++j)
        {
            if (s[j] == '(')
            {
                ++bal;
            }
            else
                --bal;
            if (bal < 0)
            {
                ++ans;
                ++bal;
            }
        }
        cout << ans << "\n";
    }
}
