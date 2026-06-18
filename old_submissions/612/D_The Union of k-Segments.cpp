#include <bits/stdc++.h>

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
    int n, k;
    cin >> n >> k;
    vpii a(n);
    vi b;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        b.push_back(a[i].first);
        b.push_back(a[i].second);
    }
    sort(b.begin(), b.end());
    map<int, int> sm;
    sm[b[0]] = 0;
    vi la(1);
    la[0] = b[0];
    int c = 1;
    for (int i = 1; i < b.size(); ++i)
    {
        if (b[i] != b[i - 1])
        {
            sm[b[i]] = c;
            la.push_back(b[i]);
            ++c;
        }
    }
    vi cnt(2 * (c + 1), 0);
    for (int i = 0; i < n; ++i)
    {
        ++cnt[sm[a[i].first] * 2];
        --cnt[sm[a[i].second] * 2 + 1];
    }
    int bal = 0;
    for (int i = 0; i < cnt.size(); ++i)
    {
        bal += cnt[i];
        cnt[i] = bal;
    }
    int r = 0;
    vpii anss;
    for (int l = 0; l < cnt.size(); l = l + 2 - (l & 1))
    {
        r = l;
        while (r + 1 < cnt.size() && cnt[r + 1] >= k && cnt[r] >= k)
        {
            ++r;
        }
        if (cnt[l] >= k)
        {
            anss.push_back({la[(l >> 1)], la[(r >> 1)]});
        }
        l = r;
    }
    sort(anss.begin(), anss.end());
    cout << anss.size() << "\n";
    for (pii elem : anss)
    {
        cout << elem.first << " " << elem.second << "\n";
    }
}

/*
*/
