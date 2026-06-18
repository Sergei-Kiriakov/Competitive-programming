#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<vvi> vvvi;
typedef std::vector<vvvi> vvvvi;
typedef std::vector<std::string> vs;
typedef std::vector<bool> vb;
typedef std::vector<vb> vvb;
typedef std::vector<double> vd;
typedef std::vector<vd> vvd;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
typedef std::vector<vpii> vvpii;
using ull = unsigned long long;

using namespace std;

const int mod = 1e9 + 7, MAXN = 1e6 + 6;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    string anss;
    for (int i = 0; i < n; ++i)
    {
        if (k - ans >= max('z' - s[i], s[i] - 'a'))
        {
            if ('z' - s[i] > s[i] - 'a')
            {
                anss.push_back('z');
            }
            else
            {
                anss.push_back('a');
            }
            ans += max('z' - s[i], s[i] - 'a');
        }
        else
        {
            if ('z' - s[i] > s[i] - 'a')
            {
                anss.push_back(s[i] + (k - ans));
            }
            else
            {
                anss.push_back(s[i] - (k - ans));
            }
            ans = k;
        }
    }
    if (ans != k)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << anss << "\n";
    }
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    solve();
}

/*
*/
