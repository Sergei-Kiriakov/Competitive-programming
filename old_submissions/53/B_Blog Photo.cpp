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
    int h, w;
    cin >> h >> w;
    int ans_h = -1, ans_w = -1;
    int ans = 0;
    for (int h1 = 1; h1 <= h; h1 = (h1 << 1))
    {
        int w1 = -1;
        if (100 * h1 <= 125 * w)
        {
            if (8 * w > 10 * h1)
            {
                w1 = 10 * h1 / 8;
            }
            else
            {
                w1 = w;
            }
            if (w1 * h1 >= ans)
            {
                ans = w1 * h1;
                ans_h = h1;
                ans_w = w1;
            }
        }
    }
    for (int w1 = 1; w1 <= w; w1 = (w1 << 1))
    {
        int h1 = -1;
        if (10 * h >= 8 * w1)
        {
            if (100 * h > 125 * w1)
            {
                h1 = 125 * w1 / 100;
            }
            else
            {
                h1 = h;
            }
            if (w1 * h1 > ans)
            {
                ans = w1 * h1;
                ans_h = h1;
                ans_w = w1;
            }
            else if (w1 * h1 == ans && ans_h < h1)
            {
                ans = w1 * h1;
                ans_h = h1;
                ans_w = w1;
            }
        }
    }
    cout << ans_h << " " << ans_w << endl;
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
