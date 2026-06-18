#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; ++k)
    {
        int n, p = 0, c = 0, div = 0;
        cin >> n;
        bool flag = true;
        for (int i = 0; i < n; ++i)
        {
            int p1, c1;
            cin >> p1 >> c1;
            if (p1 - c1 < div || p1 < p1 || c1 < c)
                flag = false;
            p = p1;
            c = c1;
            div = p1 - c1;
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
