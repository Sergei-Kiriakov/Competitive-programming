#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> ans;
    if (n % 2 == 0)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        while (n != 1)
        {
            if ((n - 1) / 2 % 2 == 1)
            {
                n = (n - 1) / 2;
                ans.push_back(2);
            }
            else
            {
                n = (n + 1) / 2;
                ans.push_back(1);
            }
        }
        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        for (int el : ans)
        {
            cout << el << " ";
        }
        cout << endl;
    }
}

int32_t main()
{
    // ofstream cout("sum.out");
    // ifstream cin("sum.in");
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