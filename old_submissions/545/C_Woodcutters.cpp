#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<vvi> vvvi;
typedef std::vector<vvvi> vvvvi;
typedef std::vector<std::string> vs;
typedef std::vector<bool> vb;
typedef std::vector<vb> vvb;
typedef std::vector<double> vd;
typedef std::vector<vd> vvd;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
typedef std::vector<vpii> vvpii;
using ull = unsigned long long;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int> > trees(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> trees[i].first >> trees[i].second;
    }
    int ans = 1;
    int last_busy = -1e10;
    for (int i = 0; i < n - 1; ++i)
    {
        int x = trees[i].first, h = trees[i].second;
        if (x - h > last_busy)
        {
            ++ans;
            last_busy = x;
        }
        else if (x + h < trees[i + 1].first)
        {
            ++ans;
            last_busy = x + h;
        }
        else
        {
            last_busy = x;
        }
    }
    cout << ans << "\n";
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
