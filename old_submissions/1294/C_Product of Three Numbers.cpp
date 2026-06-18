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
    int n;
    cin >> n;
    vi ans;
    for (int i = 2; i * i < n + 1 && ans.size() < 1; ++i)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            n /= i;
        }
    }
    for (int i = 2; i * i < n + 1 && ans.size() < 2; ++i)
    {
        if (n % i == 0 && ans[0] != i)
        {
            ans.push_back(i);
            n /= i;
        }
    }
    if (ans.size() == 2 && ans[1] != n)
    {
        cout << "YES" << "\n";
        cout << ans[0] << " " << ans[1] << " " << n << "\n";
    }
    else
    {
        cout << "NO" << "\n";
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
