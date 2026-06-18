#include <bits/stdc++.h>
//#define int long long

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

constexpr int mod = 998244353, p = 179;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n, m;
    cin >> n >> m;
    vi a(n);
    vector<set<int> > b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        --a[i];
    }
    set<int> ss;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --v;
        --u;
        b[u].insert(v);
        if (v == a.back())
            ss.insert(u);
    }
    int ans = 0;
    set<int> s;
    for (int i = n - 2; i > -1; --i)
    {
        //cerr << a[i] << endl;
        if (ss.count(a[i]))
        {
            int cnt = 0;
            for (int u : b[a[i]])
            {
                if (s.count(u))
                    ++cnt;
            }
            //cerr << cnt << " " << s.size() << endl;
            if (cnt == s.size())
            {
                ++ans;
            }
            else
            {
                s.insert(a[i]);
            }
        }
        else
        {
            s.insert(a[i]);
        }
    }
    cout << ans << endl;
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
