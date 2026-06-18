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
        int x, y, n;
        cin >> x >> y >> n;
        cout << ((n - y) / x) * x + y << "\n";
    }
}
