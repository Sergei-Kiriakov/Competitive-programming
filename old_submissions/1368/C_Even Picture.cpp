#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << 15 + 7 * (n - 1) << "\n";
    for (int i = -2; i < 2 * n + 1; ++i)
    {
        cout << 0 << " " << i << "\n";
        if (i == -2)
        {
            cout << -2 << " " << i << "\n";
            cout << -1 << " " << i << "\n";
        }
        else if (i == -1)
        {
            cout << -2 << " " << i << "\n";
        }
        else if (i == 2 * n)
        {
            if (i % 4 != 0)
            {
                cout << 2 << " " << i << "\n";
                cout << 1 << " " << i << "\n";
            }
            else
            {
                cout << -2 << " " << i << "\n";
                cout << -1 << " " << i << "\n";
            }
        }
        else if (i % 2 == 0)
        {
            cout << -2 << " " << i << "\n";
            cout << -1 << " " << i << "\n";
            cout << 2 << " " << i << "\n";
            cout << 1 << " " << i << "\n";
        }
        else if ((i - 1) % 4 == 0)
        {
            cout << 2 << " " << i << "\n";
        }
        else
        {
            cout << -2 << " " << i << "\n";
        }
    }
}
