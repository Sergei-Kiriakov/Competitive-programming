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

int gcd (int a, int b)
{
    while (b != 0)
    {
        a %= b;
        swap(a, b);
    }
    return a;
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
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
    }
    map<tuple<int, int, int>, int> c;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int a1 = a[j].second - a[i].second, b1 = -(a[j].first - a[i].first);
            int g = gcd(abs(a1), abs(b1));
            a1 /= g;
            b1 /= g;
            if (a1 < 0)
            {
                a1 = -a1;
                b1 = -b1;
            }
            else if (a1 == 0)
            {
                b1 = abs(b1);
            }
            int x1 = (a[i].first - a[j].first) * (a[i].first - a[j].first);
            int y1 = (a[i].second - a[j].second) * (a[i].second - a[j].second);
            ++c[{a1, b1, x1 + y1}];
        }
    }
    int ans = 0;
    for (auto it = c.begin(); it != c.end(); ++it)
    {
        int g;
        tuple<int, int, int> b;
        tie(b, g) = (*it);
        ans += g * (g - 1) / 2;
        //cout << g << "\n";
    }
    cout << ans / 2 << "\n";
}

/*
5
1 2 3 4 5
1 3
2 3
*/
