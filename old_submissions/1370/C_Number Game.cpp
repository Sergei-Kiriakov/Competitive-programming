#include <bits/stdc++.h>
using namespace std;
#define int long long

bool is_prime(int n)
{
    int d = 2;
    bool ans = true;
    while (d * d <= n)
    {
        if (n % d == 0)
        {
            ans = false;
        }
        ++d;
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int j = 0; j < t; ++j)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "FastestFinger" << "\n";
        }
        else if (n % 2 == 1 || n == 2)
        {
            cout << "Ashishgup" << "\n";
        }
        else
        {
            int count1 = 0;
            while (n % 2 == 0)
            {
                n /= 2;
                ++count1;
            }
            if (n == 1 || (count1 == 1 && is_prime(n)))
            {
                cout << "FastestFinger" << "\n";
            }
            else
            {
                cout << "Ashishgup" << "\n";
            }
        }
    }
}
