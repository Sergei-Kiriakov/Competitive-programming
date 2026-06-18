#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<vvi> vvvi;
typedef std::vector<vvvi> vvvvi;
typedef std::vector<std::string> vs;
typedef std::vector<bool> vb;
typedef std::vector<vb> vvb;
typedef std::vector<double> vd;
typedef std::vector<vd> vvd;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
typedef std::vector<vpii> vvpii;
using ull = unsigned long long;

using namespace std;

const int mod = 1e9 + 7, MAXN = 1e6 + 6;

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int ans = 0;
    int ind1 = -2, ind2 = -2;
    int l = 0, r = 0;
    int cnt = 1;
    set<int> c;
    c.insert(a[0]);
    vi cc(MAXN, 0);
    ++cc[a[r]];
    while (l < n)
    {
        while (r + 1 < n && (c.size() < k || (c.size() == k && c.count(a[r + 1]) != 0)))
        {
            c.insert(a[r + 1]);
            ++cc[a[r + 1]];
            ++r;
        }
        if (ans < r - l + 1)
        {
            ans = r - l + 1;
            ind1 = l + 1;
            ind2 = r + 1;
        }
        --cc[a[l]];
        if (cc[a[l]] == 0)
            c.erase(a[l]);
        //cerr << l << " " << a[l] << " " << cc[a[l]] << "\n";
        ++l;
    }
    //cerr << ans << "\n";
    cout << ind1 << " " << ind2 << "\n";
}

/*
*/
