#include <bits/stdc++.h>
//#define int long long

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

const int N = 10000000 + 100;
vb prime(N, true);

void sieve ()
{
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < N; ++i)
    {
        if (prime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n;
    cin >> n;
    vi cnt(N, 0);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ++cnt[x];
    }
    sieve();
    vi primes;
    for (int i = 2; i < N; ++i)
    {
        if (prime[i])
        {
            primes.push_back(i);
        }
    }
    vi ans (primes.size(), 0);
    for (int i = 0; i < primes.size(); ++i)
    {
        int u = primes[i];
        for (int j = u; j < N; j += u)
        {
            ans[i] += cnt[j];
        }
    }
    vi pr(ans.size() + 10, 0);
    for (int i = 1; i < pr.size(); ++i)
    {
        pr[i] = pr[i - 1] + ans[i - 1];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        int L = lower_bound(primes.begin(), primes.end(), l) - primes.begin();
        int R = lower_bound(primes.begin(), primes.end(), r) - primes.begin();
        if (primes[R] != r)
            --R;
        cout << pr[R + 1] - pr[L] << endl;
    }
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
