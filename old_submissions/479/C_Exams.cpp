#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179, MAX = 1e4 * 4;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    int min1 = a[n - 1].second;
    bool er = false;
    for (int i = n - 2; i > -1 && a[i].first > min1; --i)
    {
        if (a[i].second > min1)
        {
            //cout << i << "\n";
            er = true;
        }
        else
        {
            min1 = a[i].second;
        }
    }
    if (er)
    {
        cout << a[n - 1].first << "\n";
    }
    else
    {
        cout << a[n - 1].second << "\n";
    }
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    solve();
    //solve();
    return 0;
}
