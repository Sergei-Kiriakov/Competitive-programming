#include <bits/stdc++.h>
#define int long long

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<vvi> vvvi;
typedef std::vector<std::string> vs;
typedef std::vector<bool> vb;
typedef std::vector<vb> vvb;
typedef std::vector<double> vd;
typedef std::vector<vd> vvd;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
typedef std::vector<vpii> vvpii;

using namespace std;

constexpr int mod = 998244353, p = 179;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int x, y, ax, ay, bx, by;
    cin >> x >> y >> ax >> ay >> bx >> by;
    int x1, y1, t;
    cin >> x1 >> y1 >> t;
    vpii a;
    int nx = x, ny = y;
    int big  = 5 * 1e16;
    while (nx < big && ny < big)
    {
        a.push_back({nx, ny});
        nx = ax * nx + bx;
        ny = ay * ny + by;
    }
    int ans = 0;
    int n = a.size();
    for (int i = 0; i < n; ++i)
    {
        int xx = a[i].first, yy = a[i].second;
        int cnt = t - abs(xx - x1) - abs(yy - y1);
        if (cnt >= 0)
            ans = max(ans, 1ll);
        for (int j = i - 1; j > -1 && cnt > 0; --j)
        {
            cnt -= abs(a[j].first - a[j + 1].first);
            cnt -= abs(a[j].second - a[j + 1].second);
            if (cnt >= 0)
                ans = max(ans, i - j + 1);
        }
        int x2 = a[0].first, y2 = a[0].second;
        for (int j = i + 1; j < n && cnt > 0; ++j)
        {
            cnt -= abs(a[j].first - x2);
            cnt -= abs(a[j].second - y2);
            x2 = a[j].first;
            y2 = a[j].second;
            if (cnt >= 0)
                ans = max(ans, j + 1);
        }
    }
    cout << ans << endl;
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
