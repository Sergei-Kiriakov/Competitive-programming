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
    int h1, h2;
    int a, b;
    cin >> h1 >> h2 >> a >> b;
    int d = 12, d1 = 8;
    if (a * d1 + h1 >= h2)
    {
        cout << 0 << "\n";
    }
    else if (b >= a)
    {
        cout << -1 << "\n";
    }
    else
    {
        int h = a * d1 + h1;
        int ans = 0;
        while (true)
        {
            ++ans;
            h -= b * d;
            h += a * d;
            if (h >= h2)
            {
                cout << ans << "\n";
                return 0;
            }
        }
    }
}

/*
*/
