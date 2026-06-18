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
vector<bool> primes;

void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if(a[i][n - 1] == '1')
            a[i][n - 1] = '2';
        if (a[n - 1][i] == '1')
            a[n - 1][i] = '2';
    }
    for (int j = n - 1; j > -1; --j)
    {
        for (int i = n - 1; i > -1; --i)
        {
            if (i - 1 > -1 && a[i][j] == '2' && a[i - 1][j] == '1')
            {
                a[i - 1][j] = '2';
            }
            if (j - 1 > -1 && a[i][j] == '2' && a[i][j - 1] == '1')
            {
                a[i][j - 1] = '2';
            }
        }
    }
    bool ans = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] == '1')
            {
                ans = false;
            }
        }
    }
    if (ans)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }    
}
