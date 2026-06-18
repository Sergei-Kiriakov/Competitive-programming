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
        int n, count1 = 0, count2 = 0, z = 0;
        cin >> n;
        while (n % 3 == 0)
        {
            n /= 3;
            ++count1;
        }
        while (n % 2 == 0)
        {
            n /= 2;
            ++count2;
        }
        if (n == 1 && count1 >= count2)
        {
            if (count2 > count1)
            {
                cout << count2 << "\n";
            }
            else
            {
                cout << count1 + (count1 - count2) << "\n";
            }
        }
        else
        {
            cout << -1 << "\n";
        }
    }
}
