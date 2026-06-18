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
using mii = std::map<int, int>;
using ull = unsigned long long;
using vs = std::vector<std::string>;

using namespace std;

constexpr int MOD = 1e9 + 7, P = 179, maxn = 300 + 3;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    string s;
    int m;
    cin >> s >> m;
    int n = s.size();
    for (int i = 0; i < m; ++i)
    {
        int l, r, k;
        cin >> l >> r >> k;
        --l; --r;
        string c = s;
        int n1 = r - l + 1;
        for (int i = l; i < r + 1; ++i)
        {
            c[(i + k - l) % n1 + l] = s[i];
        }
        for (int i = 0; i < n; ++i)
        {
            if (i < l || i > r)
                c[i] = s[i];
        }
        s = c;
    }
    cout << s << "\n";
}

/*
*/
