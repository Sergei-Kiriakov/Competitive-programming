#include <bits/stdc++.h>
#define int int64_t

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

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n, p;
    cin >> n >> p;
    vs a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int d = 1;
    int ans = p / 2;
    for (int i = n - 2; i > -1; --i)
    {
        if (a[i] == "half")
        {
            ans += p * d;
            d *= 2;
        }
        else
        {
            ans += p * d + p / 2;
            d *= 2;
            ++d;
        }
    }
    cout << ans << "\n";
}

/*
*/
