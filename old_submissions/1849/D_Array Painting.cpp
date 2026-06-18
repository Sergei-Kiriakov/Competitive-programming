//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod1 = 1e9 + 93, mod2 = 1e9 + 21, d = 179;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> col(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int l = 0, r = 0;
    int ans = 0;
    while (l < n)
    {
        if (a[l] != 0)
        {
            bool est2 = false;
            r = l - 1;
            while (r + 1 < n and a[r + 1] != 0)
            {
                if (a[r + 1] == 2)
                    est2 = true;
                ++r;
            }
            ++ans;
            for (int i = l; i < r + 1; ++i)
            {
                col[i] = 1;
            }
            if (est2)
            {
                col[max(l - 1, 0ll)] = 1;
                col[min(r + 1, n - 1)] = 1;
            }
            else
            {
                if (col[max(l - 1, 0ll)] == 0)
                    col[max(l - 1, 0ll)] = 1;
                else
                    col[min(r + 1, n - 1)] = 1;
            }
            l = r;
        }
        ++l;
    }
    for (int i = 0; i < n; ++i)
    {
        if (col[i] == 0)
        {
            ++ans;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
//    ofstream cout("sum.out");
//    ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/