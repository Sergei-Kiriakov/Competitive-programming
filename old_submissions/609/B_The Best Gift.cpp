#include <bits/stdc++.h>
#define int long long
#define double long double

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vvvi = std::vector<vvi>;
using vvvvi = std::vector<vvvi>;
using vb = std::vector<bool>;
using vvb = std::vector<vb>;
using pii = std::pair<int, int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
using mii = std::map<int, int>;
using ull = unsigned long long;
using vs = std::vector<std::string>;

using namespace std;

constexpr int MOD = 1e9 + 7, P = 179, maxn = 300 + 3;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n, m;
    cin >> n >> m;
    vi a(n);
    vi cnt(m + 1, 0);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++cnt[a[i]];
    }
    int ans = 0;
    for (int i = 0; i < m + 1; ++i)
    {
        if (cnt[i] != 0)
        {
            ans += cnt[i] * (n - cnt[i]);
        }
    }
    cout << ans / 2 << endl;
}

/*
1
6
)((()(
*/
