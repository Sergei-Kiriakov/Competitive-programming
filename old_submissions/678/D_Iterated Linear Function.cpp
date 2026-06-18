#include <bits/stdc++.h>
#define int int64_t
#define double long double

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

constexpr int mod = 1e9 + 7, p = 179, MAXN = 1e7 + 1;

int binpow (int a, int n)
{
    int ans = 1;
    while (n != 0)
    {
        if (n & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}

int inverse_mod(int n)
{
    return binpow(n, mod - 2);
}

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int a, b, n, x;
    cin >> a >> b >> n >> x;
    if (a == 1)
    {
        cout << (x + b * (n % mod)) % mod << "\n";
    }
    else
    {
        int c1 = (binpow(a, n) * x) % mod;
        int c2 = (b * (binpow(a, n) - 1)) % mod;
        c2 = (c2 * inverse_mod(a - 1)) % mod;
        cout << (c1 + c2) % mod << "\n";
    }
}

/*
5
1 2 3 4 5
1 3
2 3
*/
