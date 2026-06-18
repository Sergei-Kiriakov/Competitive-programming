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
        int a, b, n ,m;
        cin >> a >> b >> n >> m;
        int c = min(a, b);
        if (c < m || !(a + b >= n + m))
        {
            cout << "No" << "\n";
        }
        else
        {
            cout << "Yes" << "\n";
        }
    }
}
