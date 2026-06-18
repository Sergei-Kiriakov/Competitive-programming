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

constexpr int mod = 1e9 + 7, p = 179;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int f (vpii a, int c, int b, int m)
{
    int cnt = 0, ans = a[0].second;
    int n = a.size();
    for (int i = 0; i < n; ++i)
    {
        if (a[i].first != b + c * (i - cnt))
        {
            ++cnt;
            ans = a[i].second;
        }
    }
    if (cnt > m)
    {
        return -1;
    }
    return ans + 1;
}

vpii copyy(vpii a, int j)
{
    int n = a.size();
    vpii ans;
    for (int i = 0; i < n; ++i)
    {
        if (i != j)
            ans.push_back(a[i]);
    }
    return ans;
}

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n;
    cin >> n;
    vpii a(n);
    vi c;
    int h = 0;
    int maxx = -1;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        c.push_back(x);
        c.push_back(y);
        if (x < y)
            swap(x, y);
        a[i] = {x, y};
        h += y;
    }
    sort(c.begin(), c.end());
    sort(a.begin(), a.end());
    int j = n - 1;
    int ans = 1e9;
    for (int i = c.size() - 1; i > -1; --i)
    {
        while (j > -1 && a[j].first > c[i])
        {
            int x = a[j].first, y = a[j].second;
            h -= y;
            h += x;
            maxx = max(maxx, y);
            --j;
        }
        if (maxx <= c[i])
        {
            ans = min(ans, c[i] * h);
        }
    }
    cout << ans << endl;
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
