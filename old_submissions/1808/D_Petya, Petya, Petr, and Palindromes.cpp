#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long ans = 0;
    for (int i = 0; i + k - 1 < n; ++i)
    {
        int j = i + k - 1;
        for (int p = 0; p < k / 2; ++p) ans += a[i + p] != a[j - p];
    }
    cout << ans << "\n";
}