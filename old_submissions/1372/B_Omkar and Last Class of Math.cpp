#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, mod = 1e9 + 7;
    cin >> t;
    for (int j = 0; j < t; ++j)
    {
        int n, nn, d = 2, maxd = 0;
        cin >> n;
        nn = n;
        while (d * d <= n)
        {
            if (n % d == 0 && (n - d) % d == 0)
            {
                maxd = max(maxd, d);
            }
            if (n % d == 0 && (n - (n / d)) % (n / d) == 0)
            {
                maxd = max(maxd, (n / d));
            }
            ++d;
        }
        if (maxd == 0)
        {
            cout << n - 1 << " " << 1 << "\n";
        }
        else
        {
            cout << maxd << " " << n - maxd << "\n";
        }
    }
}
