#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        string s;
        cin >> n >> s;
        int r = -1, l = -1;
        bool flag = true;
        for (int j = 0; j < n; ++j)
        {
            if (flag && s[j] == '1')
            {
                flag = false;
                l = j;
            }
            if (s[j] == '0')
            {
                r = j;
            }
        }
        for (int j = 0; j < n; ++j)
        {
            if (!(j >= l && j < r && l != -1 && r != -1))
            {
                cout << s[j];
            }
        }
        cout << "\n";
    }
}
