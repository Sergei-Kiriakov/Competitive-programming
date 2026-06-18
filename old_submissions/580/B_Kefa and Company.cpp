#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179, MAX = 1e4 * 4;

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<pair<int, int> > friends(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> friends[i].first >> friends[i].second;
    }
    sort(friends.begin(), friends.end());
    int left = 0, right = 0;
    int ans = 0, sum_seg = friends[0].second;
    while (left < n)
    {
        while ((right + 1 < n && friends[right + 1].first - friends[left].first < d) || right < left)
        {
            sum_seg += friends[right + 1].second;
            ++right;
        }
        ans = max(ans, sum_seg);
        sum_seg -= friends[left].second;
        ++left;
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
    /*
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    */
    solve();
    return 0;
}
