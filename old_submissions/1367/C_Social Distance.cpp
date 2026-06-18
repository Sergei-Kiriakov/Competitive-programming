#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int j = 0; j < t; ++j)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int l = -1e9, ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0' && i - l > k)
            {
                ++ans;
                l = i;
            }
            if (s[i] == '1' && i - l <= k)
            {
                --ans;
            }
            if (s[i] == '1')
            {
                l = i;
            }
        }
        cout << ans << "\n";
    }
}
