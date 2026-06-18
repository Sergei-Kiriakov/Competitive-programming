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
    vpii a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    bool ans = true;
    int start = -1, finish = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i].second != i || (start != -1 && i <= a[start].second))
        {
            if (start != -1)
            {
                if (a[i].second != finish - 1)
                {
                    //cout << a[i].first << " " << a[i].second << " " << i << " " << finish << "\n";
                    ans = false;
                }
                --finish;
            }
            else
            {
                start = i;
                finish = a[i].second;
            }
        }
    }
    if (ans)
    {
        cout << "yes" << "\n";
        if (start == -1)
        {
            cout << 1 << " " << 1 << "\n";
        }
        else
        {
            cout << start + 1 << " " << a[start].second + 1 << "\n";
        }
    }
    else
    {
        cout << "no" << "\n";
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
