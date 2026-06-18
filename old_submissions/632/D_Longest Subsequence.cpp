#include <bits/stdc++.h>
#define int int64_t

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

constexpr int mod = 1e9 + 7, p = 179;


int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n, m;
    cin >> n >> m;
    vi cnt(m + 1, 0);
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] <= m)
        {
            ++cnt[a[i]];
        }
    }
    vi ans(m + 1, 0);
    for (int i = 1; i < m + 1; ++i)
    {
        for (int j = 1; j * i < m + 1; ++j)
        {
            ans[i * j] += cnt[i];
        }
    }
    int anss = 0;
    int ind = 1;
    for (int i = 0; i < m + 1; ++i)
    {
        if (anss < ans[i])
        {
            ind = i;
            anss = ans[i];
        }
    }
    cout << ind << " " << anss << "\n";
    for (int i = 0; i < n; ++i)
    {
        if (ind % a[i] == 0)
        {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
}

/*
*/
