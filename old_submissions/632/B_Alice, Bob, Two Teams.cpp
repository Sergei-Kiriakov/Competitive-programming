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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'B')
            ans += a[i];
    }
    int anss = ans;
    int a1 = 0, b1 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'A')
        {
            a1 += a[i];
        }
        else
        {
            b1 += a[i];
        }
        anss = max(anss, ans - b1 + a1);
    }
    a1 = 0;
    b1 = 0;
    for (int i = n - 1; i > -1; --i)
    {
        if (s[i] == 'A')
        {
            a1 += a[i];
        }
        else
        {
            b1 += a[i];
        }
        anss = max(anss, ans - b1 + a1);
    }
    cout << anss << "\n";
}

/*
*/
