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

bool check(int day, vi &a, vi &b, vpii &d, vpii &e, int need, int mon)
{
    int n = a.size();
    if (day == n)
        return false;
    int min1 = 1e9, min2 = 1e9;
    for (int i = 0; i <= day; ++i)
    {
        min1 = min(min1, a[i]);
        min2 = min(min2, b[i]);
    }
    int n1 = d.size(), n2 = e.size();
    int sum1 = 0, sum2 = 0;
    bool ans = false;
    int i = 0, j = min(n2, need);
    for (int f = 0; f < j; ++f)
    {
        sum2 += e[f].first;
    }
    while (i < n1 + 1)
    {
        if (i + j >= need)
        {
            if (sum2 * min2 + sum1 * min1 <= mon)
                ans = true;
        }
        if (i < n1)
            sum1 += d[i].first;
        ++i;
        while (j > 0 && i + j > need)
        {
            sum2 -= e[j - 1].first;
            --j;
        }
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    vpii c(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> c[i].first >> c[i].second;
    }
    vpii d, e;
    for (int i = 0; i < m; ++i)
    {
        if (c[i].first == 1)
            d.push_back({c[i].second, i + 1});
        else
            e.push_back({c[i].second, i + 1});
    }
    sort(d.begin(), d.end());
    sort(e.begin(), e.end());
    int l = -1, r = n;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (check(mid, a, b, d, e, k, s))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    if (r == n)
    {
        cout << -1;
    }
    else
    {
        cout << r + 1 << endl;
        int min1 = 1e9, min2 = 1e9, ind1 = -1, ind2 = -1;
        for (int i = 0; i <= r; ++i)
        {
            if (min1 > a[i])
            {
                ind1 = i;
                min1 = a[i];
            }
            if (min2 > b[i])
            {
                ind2 = i;
                min2 = b[i];
            }
        }
        int n1 = d.size(), n2 = e.size();
        int sum1 = 0, sum2 = 0;
        int i = 0, j = min(n2, k);
        for (int f = 0; f < j; ++f)
        {
            sum2 += e[f].first;
        }
        while (i < n1 + 1)
        {
            if (i + n2 >= k)
            {
                if (sum2 * min2 + sum1 * min1 <= s)
                {
                    for (int f = 0; f < i; ++f)
                    {
                        cout << d[f].second << " " << ind1 + 1 << endl;
                    }
                    for (int g = 0; g < k - i; ++g)
                    {
                        cout << e[g].second << " " << ind2 + 1 << endl;
                    }
                    return 0;
                }
            }
            if (i < n1)
                sum1 += d[i].first;
            ++i;
            while (j > 0 && i + j > k)
            {
                sum2 -= e[j - 1].first;
                --j;
            }
        }
    }
}

/*
1
6
)((()(
*/
