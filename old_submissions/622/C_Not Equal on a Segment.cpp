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
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vpii st;
    vi c(n, -2);
    for (int i = n - 1; i > -1; --i)
    {
        while (st.size() != 0 && st.back().first != a[i])
        {
            c[st.back().second] = i;
            st.pop_back();
        }
        st.push_back({a[i], i});
    }
    for (int i = 0; i < m; ++i)
    {
        int l, r, x;
        cin >> l >> r >> x;
        --l; --r;
        if (a[r] != x)
        {
            cout << r + 1 << "\n";
        }
        else
        {
            if (c[r] >= l)
            {
                cout << c[r] + 1 << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
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
