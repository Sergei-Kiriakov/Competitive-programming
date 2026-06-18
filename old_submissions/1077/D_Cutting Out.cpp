#include <bits/stdc++.h>

#define int long long
#define double long double

using namespace std;

constexpr int mod = 1e9 + 7, N = 2 * 1e5 + 5;

bool check (int mid, vector<pair<int, int> > &b, int k)
{
    int n = b.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cnt += b[i].first / mid;
    }
    return cnt >= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<pair<int, int> > b(N, {0, 0});
    for (int i = 0; i < N; ++i)
    {
        b[i].second = i + 1;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++b[a[i] - 1].first;
    }
    sort(b.rbegin(), b.rend());
    int l = 0, r = 1e9;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (check(mid, b, k))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < b[i].first / l && ans.size() < k; ++j)
        {
            ans.push_back(b[i].second);
        }
    }
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    //ofstream cout("output.txt");
    //ifstream cin("input.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    //solve();
    return 0;
}

/*
*/