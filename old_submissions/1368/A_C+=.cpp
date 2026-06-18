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
        int n, a, b;
        cin >> a >> b >> n;
        if (a > b)
        {
            int c = a;
            a = b;
            b = c;
        }
        int f1 = 0, f2 = 1, count1 = 0;
        while (f1 * a + f2 * b <= n)
        {
            ++count1;
            int c = f1 + f2;
            f1 = f2;
            f2 = c;
        }
        cout << count1 << "\n";
    }
}
