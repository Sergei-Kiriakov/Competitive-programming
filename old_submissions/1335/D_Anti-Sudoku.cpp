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

void sieve(int n = MAXN)
{
    primes.resize(n + 1, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i * i < n + 1; ++i)
        if (primes[i])
            if (i * 1ll * i <= n)
                for (int j = i * i; j < n + 1; j += i)
                    primes[j] = false;
}

void solve()
{
    int n = 9;
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }
    s[0][0] = (s[0][0] - '0') % 9 + '0' + 1;
    s[3][1] = (s[3][1] - '0') % 9 + '0' + 1;
    s[6][2] = (s[6][2] - '0') % 9 + '0' + 1;
    s[1][3] = (s[1][3] - '0') % 9 + '0' + 1;
    s[4][4] = (s[4][4] - '0') % 9 + '0' + 1;
    s[7][5] = (s[7][5] - '0') % 9 + '0' + 1;
    s[2][6] = (s[2][6] - '0') % 9 + '0' + 1;
    s[5][7] = (s[5][7] - '0') % 9 + '0' + 1;
    s[8][8] = (s[8][8] - '0') % 9 + '0' + 1;
    for (int i = 0; i < n; ++i)
    {
        cout << s[i] << "\n";
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
