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
    string s;
    cin >> s;
    vi cnt(30, 0);
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        ++cnt[s[i] - 'a'];
    }
    int l = 0, r = 29;
    while (l < r)
    {
        while (l < r && cnt[l] % 2 == 0)
        {
            ++l;
        }
        while (r > l && cnt[r] % 2 == 0)
        {
            --r;
        }
        ++cnt[l];
        --cnt[r];
        ++l;
        --r;
    }
    string ans = "";
    for (int i = 0; i < 30; ++i)
    {
        for (int j = 0; j < cnt[i] / 2; ++j)
        {
            ans += 'a' + i;
        }
    }
    if (n % 2 == 1)
    {
        int k = 0;
        for (;cnt[k] % 2 == 0; ++k);
        ans += 'a' + k;
    }
    for (int i = 29; i > -1; --i)
    {
        for (int j = 0; j < cnt[i] / 2; ++j)
        {
            ans += 'a' + i;
        }
    }
    cout << ans << endl;
}

/*
1
6
)((()(
*/
