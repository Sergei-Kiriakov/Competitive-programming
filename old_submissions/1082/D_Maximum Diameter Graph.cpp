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
    vector<int> a(n);
    vector<int> b, c;
    int sum_b = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > 1)
        {
            sum_b += a[i];
            b.push_back(i);
        }
        else
        {
            c.push_back(i);
        }
    }
    if (sum_b - (b.size() - 1) * 2 < c.size())
    {
        cout << "NO" << endl;
        return;
    }
    int start = -1, finish = -1;
    if (!c.empty())
    {
        start = c.back();
        c.pop_back();
    }
    else
    {
        start = b.back();
        b.pop_back();
    }
    if (!c.empty())
    {
        finish = c.back();
        c.pop_back();
    }
    else
    {
        finish = b.back();
        b.pop_back();
    }
    vector<pair<int, int> > ans;
    int last = start;
    vector<int> col = {start};
    a[start] -= 1;
    for (int i = 0; i < b.size(); ++i)
    {
        ans.push_back({last, b[i]});
        last = b[i];
        col.push_back(b[i]);
        a[b[i]] -= 2;
    }
    ans.push_back({last, finish});
    col.push_back(finish);
    a[finish] -= 1;
    int now = 0;
    for (int i = 0; i < c.size(); ++i)
    {
        while (now < col.size() and a[col[now]] <= 0)
        {
            ++now;
        }
        if (now == col.size())
        {
            cout << "NO" << endl;
            return;
        }
        ans.push_back({c[i], col[now]});
        a[col[now]] -= 1;
    }
    cout << "YES" << " " << col.size() - 1 << endl;
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
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
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/