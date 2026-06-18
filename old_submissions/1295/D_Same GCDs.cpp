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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int gcd (int a, int b)
{
    while (a != 0)
    {
        b %= a;
        swap(a, b);
    }
    return b;
}

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int a, m;
        cin >> a >> m;
        int m1 = m / gcd(a, m);
        int ans = m1, d = 2;
        while (d * d <= m1)
        {
            if (m1 % d == 0)
                ans -= ans / d;
            while (m1 % d == 0)
            {
                m1 /= d;
            }
            ++d;
        }
        if (m1 != 1)
        {
            ans -= ans / m1;
        }
        cout << ans << endl;
    }
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
