//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define remin(x, y) x = min(x, y)
#define remax(x, y) x = max(x, y)
#define lowpos(a, x) int(lower_bound(a.begin(), a.end(), x) - a.begin())
#define uppos(a, x) int(upper_bound(a.begin(), a.end(), x) - a.begin())

using namespace std;

constexpr int mod = 1e9 + 7;

void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    set<int> players;
    players.insert(x - 1);
    for (int i = 0; i < m; ++i)
    {
        set<int> temp;
        int k;
        char ask;
        cin >> k >> ask;
        if (ask == '0')
        {
            for (auto el : players)
                temp.insert((el + k) % n);
        }
        else if (ask == '1')
        {
            for (auto el : players)
                temp.insert((n + el - k) % n);
        }
        else
        {
            for (auto el : players)
                temp.insert((el + k) % n);
            for (auto el : players)
                temp.insert((n + el - k) % n);
        }
        players = temp;
    }
    cout << players.size() << endl;
    for (auto el : players)
    {
        cout << el + 1 << " ";
    }
    cout << endl;
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
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