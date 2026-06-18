//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int d = n; d > -1; --d)
    {
        bool flag = true;
        int i = 0;
        int f2 = n, f1 = d;
        while (flag && i < k - 2)
        {
            int c = f2 - f1;
            if (c > f1 || c < 0)
                flag = false;
            f2 = f1;
            f1 = c;
            ++i;
        }
        if (i == k - 2 && flag)
            ++ans;
    }
    cout << ans << endl;
}

int32_t main()
{
    //ofstream cout("sum.out");
    //ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/