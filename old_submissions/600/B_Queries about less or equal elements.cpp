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
    vi a(n), b(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j)
    {
        cin >> b[j];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; ++i)
    {
        int ans = lower_bound(a.begin(), a.end(), b[i] + 1) - a.begin();
        cout << ans << " ";
    }
    cout << endl;
}

/*
1
6
)((()(
*/
