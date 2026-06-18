#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    if (a[0] == a[n - 1])
    {
        for (int i = 0; i < n; ++i)
        {
            cout << 0 << endl;
        }
        return 0;
    }
    vector<int> ans(n, 0);
    ans[n - 1] = 1;
    sum -= a[n - 1];
    int i = n - 2;
    while (i > -1)
    {
        int j = i;
        while (j > -1 && a[j] == a[i])
        {
            --j;
        }
        if (j > -1 && ans[i + 1] == 1 && sum > a[i + 1])
        {
            for (int k = j + 1; k <= i; ++k)
            {
                ans[k] = 1;
                sum -= a[k];
            }
        }
        i = j;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
