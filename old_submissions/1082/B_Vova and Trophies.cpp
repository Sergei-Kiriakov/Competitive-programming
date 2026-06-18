//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;


const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int j = 0;
    while (s[j] == 'S')
    {
        ++j;
    }
    if (j == s.size())
    {
        cout << 0 << endl;
        return;
    }
    vector<int> a;
    int cnt = 1;
    for (int i = j + 1; i < n; ++i)
    {
        if (s[i] != s[i - 1])
        {
            a.push_back(cnt);
            cnt = 1;
        }
        else
        {
            ++cnt;
        }
    }
    a.push_back(cnt);
    int ans = a[0] + (a.size() > 2);
    for (int i = 2; i < a.size(); i += 2)
    {
        if (a[i - 1] == 1)
        {
            int dd = a[i] + a[i - 2];
            ans = max(ans, dd + (a.size() > 4));
        }
        ans = max(ans, a[i] + (a.size() > 2));
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
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/