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
vector<bool> primes;

void solve()
{
    int n;
    cin >> n;
    vi a(n), b(n), a1(n);
    int cnt_0 = 0, cnt_1 = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a1[i] = a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        cnt_0 += (b[i] == 0);
        cnt_1 += (b[i] == 1);
    }
    sort(a1.begin(), a1.end());
    if ((cnt_0 != 0 && cnt_1 != 0) || a == a1)
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
