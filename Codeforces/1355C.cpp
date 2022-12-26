#include <bits/stdc++.h>

#define int long long int

using namespace std;

const int N = 1e6 + 6;

int32_t main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> sum(N, 0);
    for (int x = a; x <= b; ++x)
    {
        sum[b + x]++;
        sum[c + x + 1]--;
    }
    int bal = 0;
    for (int i = 0; i < N; ++i)
    {
        bal += sum[i];
        sum[i] = bal;
    }
    vector<int> pref(N, 0);
    for (int i = N - 2; i > -1; --i)
    {
        pref[i] = pref[i + 1] + sum[i];
    }
    int ans = 0;
    for (int z = c; z < d + 1; ++z)
    {
        ans += pref[z + 1];
    }
    cout << ans << endl;
}

/*
*/