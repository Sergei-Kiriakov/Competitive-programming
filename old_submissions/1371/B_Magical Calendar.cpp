#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, mod = 1e9 + 7;
    cin >> t;
    for(int j = 0; j < t; ++j)
    {
        int n, r;
        cin >> n >> r;
        int c = min(n - 1, r), ans = c * (c + 1) / 2;
        if (n <= r)
        {
            ans += 1;
        }
        cout << ans << "\n";
    }
}
