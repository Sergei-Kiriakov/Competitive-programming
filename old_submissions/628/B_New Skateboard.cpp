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
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1)
    {
        cout << ((s[0] == '0') || (s[0] == '4') || (s[0] == '8')) << "\n";
    }
    else
    {
        int ans = 0;
        for (int i = 0; i + 1 < n; ++i)
        {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num % 4 == 0)
            {
                ans += i + 1;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            ans += ((s[i] == '0') || (s[i] == '4') || (s[i] == '8'));
        }
        cout << ans << "\n";
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
