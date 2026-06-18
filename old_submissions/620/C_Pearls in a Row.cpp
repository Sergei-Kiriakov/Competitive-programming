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

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    map<int, int> c;
    bool flag = false;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++c[a[i]];
        if (c[a[i]] > 1)
            flag = true;
    }
    if (!flag)
    {
        cout << -1 << endl;
        return;
    }
    c.clear();
    vpii ans;
    bool flag1 = false;
    int last = 0;
    for (int i = 0; i < n; ++i)
    {
        ++c[a[i]];
        if (c[a[i]] >= 2)
        {
            ans.push_back({last + 1, i + 1});
            last = i + 1;
            c.clear();
        }
    }
    if (ans.back().second != n)
        ans.back().second = n;
    cout << ans.size() << "\n";
    for (pii elem : ans)
    {
        cout << elem.first << " " << elem.second << "\n";
    }
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    solve();
}

/*
*/
