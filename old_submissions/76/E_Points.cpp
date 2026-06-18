#include <bits/stdc++.h>
#define int long long

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

const int N = 20000 + 100;
int d = 10000;

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n;
    cin >> n;
    vi X(N, 0), Y(N, 0);
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        ++X[x + d];
        ++Y[y + d];
    }
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        if (X[i] != 0)
        {
            for (int j = i + 1; j < N; ++j)
            {
                ans += X[i] * (j - i) * (j - i) * X[j];
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        if (Y[i] != 0)
        {
            for (int j = i + 1; j < N; ++j)
            {
                ans += Y[i] * (j - i) * (j - i) * Y[j];
            }
        }
    }
    cout << ans << endl;
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
