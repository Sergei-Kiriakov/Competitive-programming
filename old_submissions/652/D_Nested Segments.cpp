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

vi t;

int get_ans (int i)
{
    int ans = 0;
    for (; i > -1; i = (i & (i + 1)) - 1)
    {
        ans += t[i];
    }
    return ans;
}

void up (int i, int x)
{
    for (; i < t.size(); i = ((i + 1) | i))
    {
        t[i] += x;
    }
}

int get_ans (int l, int r)
{
    if (l == 0)
        return get_ans(r);
    return get_ans(r) - get_ans(l - 1);
}

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n;
    cin >> n;
    t.resize(n);
    for (int i = 0; i < n; ++i)
    {
        up(i, 1);
    }
    vector<pii> l, r;
    map<pii, int> c;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        c[{x, y}] = i;
        l.push_back({x, y});
        r.push_back({y, x});
    }
    vi ans(n, 0);
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    for (int i = 0; i < n; ++i)
    {
        pii a = l[i];
        pii b = {a.second, a.first};
        int ll = -1, rr = n - 1;
        while (rr - ll > 1)
        {
            int mid = (rr + ll) / 2;
            if (r[mid] >= b)
            {
                rr = mid;
            }
            else
            {
                ll = mid;
            }
        }
        ans[c[a]] = get_ans(0, rr - 1);
        up(rr, -1);
    }
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << "\n";
    }
}

/*
5
1 2 3 4 5
1 3
2 3
*/
