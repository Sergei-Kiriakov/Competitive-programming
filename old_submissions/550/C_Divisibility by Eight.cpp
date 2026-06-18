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

constexpr int mod = 1e9 + 7, p = 179;

int f1(string &s)
{
    int ans = -1;
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        if ((s[i] - '0') % 8 == 0)
        {
            ans = s[i] - '0';
        }
    }
    return ans;
}

int f2(string &s)
{
    int ans = -1;
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int numb = (s[i] - '0') * 10 + (s[j] - '0');
            if (numb % 8 == 0)
            {
                ans = numb;
            }
        }
    }
    return ans;
}

int f3(string &s)
{
    int ans = -1;
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                int numb = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
                if (numb % 8 == 0)
                {
                    ans = numb;
                }
            }
        }
    }
    return ans;
}

void solve()
{
    string s;
    cin >> s;
    if (f1(s) != -1)
    {
        cout << "YES" << "\n";
        cout << f1(s) << "\n";
    }
    else if (f2(s) != -1)
    {
        cout << "YES" << "\n";
        cout << f2(s) << "\n";
    }
    else if (f3(s) != -1)
    {
        cout << "YES" << "\n";
        cout << f3(s) << "\n";
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
    solve();
    //solve();
    return 0;
}
