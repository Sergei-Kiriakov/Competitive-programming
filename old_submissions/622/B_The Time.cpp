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
    int a;
    cin >> a;
    int h = 60;
    int t = (s[0] - '0') * 10 * h + (s[1] - '0') * h + (s[3] - '0') * 10 + (s[4] - '0');
    t += a;
    int mod1 = 24 * 60;
    t %= mod1;
    int a1 = t / (h * 10);
    int a2 = (t - a1 * (h * 10)) / h;
    int a3 = (t - a2 * h - a1 * h * 10) / 10;
    int a4 = (t - a2 * h - a1 * h * 10 - a3 * 10);
    char l1 = a1 + '0';
    char l2 = a2 + '0';
    char l3 = a3 + '0';
    char l4 = a4 + '0';
    cout << l1 << l2 << ":" << l3 << l4 << "\n";
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
