#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    int count1 = 0, count2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 1 && b[i] == 0)
        {
            count1++;
        }
        if (a[i] == 0 && b[i] == 1)
        {
            count2++;
        }
    }
    if (count1 == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << (count2 + 1 + count1 - 1) / count1 << endl;
    }
}
