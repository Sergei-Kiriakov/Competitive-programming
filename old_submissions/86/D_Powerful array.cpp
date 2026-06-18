#include <bits/stdc++.h>

#define int long long

using namespace std;

constexpr int mod = 998244353, N = 1e6 + 6;

int formula(vector<int> &cnt, int x)
{
    return cnt[x] * cnt[x] * x;
}

void step_r(vector<int> &a, vector<int> &cnt, int &ans, int &i, int d = 1)
{
    i += d;
    int x = a[i];
    ans -= formula(cnt, x);
    ++cnt[x];
    ans += formula(cnt, x);
}

void step_l(vector<int> &a, vector<int> &cnt, int &ans, int &i, int d = -1)
{
    int x = a[i];
    ans -= formula(cnt, x);
    --cnt[x];
    ans += formula(cnt, x);
    i += d;
}

void solve()
{
    //Алгоритм МО
    int n, t;
    cin >> n >> t;
    int sqrt = 1;
    while (sqrt * sqrt < n) ++sqrt;
    vector<int> a(n + 10, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int> > ask(t);
    for (int i = 0; i < t; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l; --r;    
        ask[i] = {l / sqrt, r, l, i};
    }
    sort(ask.begin(), ask.end());
    vector<int> ans(t);
    int l = 0, r = 0;
    int anss = 0;
    vector<int> cnt(N, 0);
    cnt[a[l]]++;
    anss += a[l];
    for (int i = 0; i < t; ++i)
    {
        int n_l = ask[i][2], n_r = ask[i][1], ind = ask[i][3];
        while (r < n_r)
        {
            step_r(a, cnt, anss, r, 1);
        }
        while (r > n_r)
        {
            step_l(a, cnt, anss, r, -1);
        }
        while (l < n_l)
        {
            step_l(a, cnt, anss, l, 1);
        }
        while (l > n_l)
        {
            step_r(a, cnt, anss, l, -1);
        }
        ans[ind] = anss;
    }
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
}

/*

*/