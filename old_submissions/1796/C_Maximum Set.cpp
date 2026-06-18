#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 998244353;

void solve1()
{
    int l, r;
    cin >> l >> r;
    int n = __lg(r / l) + 1;
    if (n == 1) cout << n << " " << (r - l + 1) << endl;
    else cout << n << " " << ((r >> (n - 1)) - l + 1) + max((r >> (n - 2)) / 3 - l + 1, 0ll) * (n - 1) << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cerr.tie(nullptr);
    // cout << fixed;
    // cout.precision(15);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve1();
    }
    return 0;
}


/*
1
codeforces
atcoder
*/