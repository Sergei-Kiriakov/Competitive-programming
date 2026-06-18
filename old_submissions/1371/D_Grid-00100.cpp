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
        int n, k;
        cin >> n >> k;
        vector<vector<int> > a(n, vector<int> (n, 0));
        if (k % n == 0)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << 2 << "\n";
        }
        int count1 = 0;
        for (int i = 0; i < k; ++i)
        {
            a[i % n][(i / n + i) % n] = 1;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int h = 0; h < n; ++h)
            {
                cout << a[i][h];
            }
            cout << "\n";
        }
    }
}
