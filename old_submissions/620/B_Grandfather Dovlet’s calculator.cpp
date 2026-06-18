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

int cal(int a)
{
    int ans = 0;
    map<int, int> c;
    c[0] = 6;
    c[1] = 2;
    c[2] = 5;
    c[3] = 5;
    c[4] = 4;
    c[5] = 5;
    c[6] = 6;
    c[7] = 3;
    c[8] = 7;
    c[9] = 6;
    if (a == 0)
    {
        return c[a];
    }
    while (a != 0)
    {
        ans += c[a % 10];
        a /= 10;
    }
    return ans;
}

void solve()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; ++i)
    {
        ans += cal(i);
    }
    cout << ans << endl;
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
