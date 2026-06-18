//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

int mod = 1e9 + 9;

void solve()
{
    int n;
    cin >> n;
    if (n < 10)
    {
        bool flag = false;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i == j)
                    continue;
                int d = n * (n + 1) / 2 - i - j;
                string s1 = to_string(i), s2 = to_string(j);
                string s = s1 + s2;
                if (stoi(s) == d)
                {
                    flag = true;
//                    cout << "For n = " << n << endl;
                    cout << 2 << " " << i << " " << j << endl;
                    break;
                }
                if (i == d + j)
                {
                    flag = true;
//                    cout << "For n = " << n << endl;
                    cout << 1 << " " << i << endl;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (!flag)
        {
//            cout << "For n = " << n << endl;
            cout << 0 << endl;
        }
    }
    else
    {
        int s = n * (n + 1) / 2;
        int d10 = 10;
        int ans1 = -1, ans2 = -1;
        while (d10 + 1 <= s)
        {
            int m = d10 + 1;
            int k = s % m;
            if (k % 2 == 0)
            {
                int d1 = k / 2;
                int k1 = (s - 2 * d1) / m;
                int anss = d10 * k1 + d1;
                int ansss = s - k1 - d1;
                if (d1 != k1 and d1 > 0 and d1 <= n and k1 > 0 and k1 <= n and d1 >= d10 / 10)
                {
                    ans1 = k1;
                    ans2 = d1;
                }
            }
            if ((m + k) % 2 == 0)
            {
                int d1 = (k + m) / 2;
                int k1 = (s - 2 * d1) / m;
                int anss = d10 * k1 + d1;
                int ansss = s - k1 - d1;
                if (d1 != k1 and d1 > 0 and d1 <= n and k1 > 0 and k1 <= n and d1 >= d10 / 10)
                {
                    ans1 = k1;
                    ans2 = d1;
                }
            }
            d10 *= 10;
        }
        if (ans1 == -1)
        {
            cout << 0 << endl;
            return;
        }
        cout << 2 << " " << ans1 << " " << ans2 << endl;
    }
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
123
*/ 