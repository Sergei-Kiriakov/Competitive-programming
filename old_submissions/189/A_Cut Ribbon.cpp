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
    int ans = 1;
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            int new_piece = n - a * i - b * j;
            if (new_piece >= 0 && new_piece % c == 0)
            {
                ans = max(ans, i + j + new_piece / c);
            }
        }
    }
    cout << ans << "\n";
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
