//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

int binPow(int a, int p)
{
    if(p == 0)
        return 1;

    if(p == 1)
        return a % mod;

    if(p % 2 == 0)
    {
        int val = binPow(a, p / 2);

        return val * val % mod;
    }
    else
    {
        return binPow(a, p - 1) * a % mod;
    }
}

void solve(const vector<int> & fact, const vector<int> &inv_fact) {
    auto comb = [&](int n, int k) -> int
            {
                return ((fact[n] * inv_fact[k]) % mod) * inv_fact[n - k] % mod;
            };

    int n, k;
    cin >> n >> k;
    int l = n / (2 * k);
    int ans1 = k * l * (l - 1) + l * (n % (2 * k));
//    ans1 %= mod;
    int ans2 = 0;
    if (l != 0) {
        int ost = n % (2 * k);
        int max_cnt2 = k - 1;
        for (int cnt2 = max(0ll, ost - (k + 1)); cnt2 * 2 <= ost and cnt2 <= max_cnt2; ++cnt2) {
            int f = comb(max_cnt2, cnt2);
            int cnt1 = ost - cnt2 * 2;
            int g = comb(k + 1 - cnt2, cnt1);
            ans2 = (ans2 + f * g) % mod;
        }
    }
    else {
        int ost = n % (2 * k) - (k + 1);
        int max_cnt2 = k - 1;
        int cnt2 = ost;
        int f = comb(max_cnt2, cnt2);
        ans2 = (ans2 + f) % mod;
    }
    cout << ans1 << " " << ans2 % mod << endl;
}

int32_t main() {
//    ofstream cout("");
//    ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<int> fact(2e5 + 1), inv_fact(2e5 + 1);

    fact[0] = 1;

    for(int i = 1; i <= 2e5; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }

    inv_fact[2e5] = binPow(fact[2e5], mod - 2);

    for(int i = 2e5 - 1; i >= 0; i--)
    {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
    }
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        solve(fact, inv_fact);
    }
}

/*
*/  