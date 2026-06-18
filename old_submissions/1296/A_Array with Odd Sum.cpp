#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n, sum = 0, count1 = 0, count2 = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int temp;
            cin >> temp;
            if (temp % 2 == 0)
                ++count2;
            else
                ++count1;
            sum += temp;
        }
        if (sum % 2 == 1 || (count2 != 0 && count1 != 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
