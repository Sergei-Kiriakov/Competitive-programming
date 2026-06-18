#include <bits/stdc++.h>
#define int int64_t
#define double long double

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

constexpr int mod = 1e9 + 7, p = 179, MAXN = 1000000;

int randi (int l, int r)
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int k = r - l + 1;
    return rng() % k + l;
}

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n, m;
    cin >> n >> m;
    vi a(n);
    vi c(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        c[a[i]] = i;
    }
    vvi d(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (c[x] > c[y])
        {
            swap(x, y);
        }
        d[x].push_back(c[y]);
    }
    int l = 0, r = -1;
    int ans = 0;
    multiset<int> s;
    s.insert(1e9);
    //cout << d[1] << d[2] << "\n";
    while (l < n)
    {
        while (r + 1 < n && r + 1 < *s.begin())
        {
            for (int i = 0; i < d[a[r + 1]].size(); ++i)
            {
                s.insert(d[a[r + 1]][i]);
            }
            ++r;
        }
        ans += (r - l + 1);
        //cout << r - l + 1 << " " << l << " " << r << "\n";
        for (int i = 0; i < d[a[l]].size(); ++i)
        {
            s.erase(s.find(d[a[l]][i]));
        }
        ++l;
    }
    cout << ans << "\n";
}

/*
5
1 2 3 4 5
1 3
2 3
*/
