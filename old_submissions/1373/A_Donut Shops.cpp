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
        int a, b, c;
        cin >> a >> b >> c;
        if (a >= c)
        {
            cout << -1 << " " << 2;
        }
        else if (a * b <= c)
        {
            cout << 1 << " " << -1;
        }
        else
        {
            cout << 1 << " " << b;
        }
        cout << "\n";
    }
}
