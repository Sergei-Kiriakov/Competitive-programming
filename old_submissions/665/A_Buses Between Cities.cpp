#include <bits/stdc++.h>
#define int int64_t
#define double long double

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

constexpr int mod = 1e9 + 7, p = 179, MAXN = 1000000;

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int a, ta, b, tb;
    cin >> a >> ta >> b >> tb;
    string time;
    cin >> time;
    int g = 5 * 60;
    int start = (time[0] - '0') * 10 * 60 + (time[1] - '0') * 60 + (time[3] - '0') * 10 + (time[4] - '0');
    int l = start - tb;
    int r = start + ta;
    int ans = 0;
    for (int i = 5 * 60; i < 24 * 60; ++i)
    {
        if ((i - g) % b == 0 && i > l && i < r)
            ++ans;
    }
    cout << ans << "\n";
}

/*
5
1 2 3 4 5
1 3
2 3
*/
