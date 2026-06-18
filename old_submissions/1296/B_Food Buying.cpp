#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int s, ans = 0;
        cin >> s;
        while (s >= 10)
        {
            ans += s - s % 10;
            s = s / 10 + s % 10;
        }
        cout << ans + s << endl;
    }
}
