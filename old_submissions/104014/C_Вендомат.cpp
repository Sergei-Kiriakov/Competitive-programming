//# GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

pair<int, int> f(string s)
{
    pair<int, int> ans = {0, 0};
    int n = s.size();
    int i = 0;
    while (i < n && s[i] != ',')
    {
        ans.first *= 10;
        ans.first += s[i] - '0';
        ++i;
    }
    i++;
    while (i < n)
    {
        ans.second *= 10;
        ans.second += s[i] - '0';
        ++i;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    pair<int, int> mon = f(s);
    vector<pair<int, string> > a;
    for (int i = 0; i < n; ++i)
    {
        string name, s1;
        cin >> name >> s1;
        pair<int, int> mon1 = f(s1);
        a.push_back({mon1.first * 100 + mon1.second, name});
    }
    sort(a.rbegin(), a.rend());
    string ans = "";
    for (int i = 0; i < n; ++i)
    {
        if (a[i].first / 100 <= mon.first && a[i].first % 100 <= mon.second)
        {
            ans = a[i].second;
            break;
        }
    }
    if (ans == "")
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
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
    //cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/