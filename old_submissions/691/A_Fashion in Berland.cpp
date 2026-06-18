#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << (a[0] == 1 ? "YES" : "NO") << "\n";
    }
    else
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == 0)
                ++cnt;
        }
        cout << (cnt == 1 ? "YES" : "NO") << "\n";
    }
}
