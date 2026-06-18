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

constexpr int mod = 1e9 + 7, p = 179;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n, m;
    cin >> n >> m;
    vvi a(n, vi (m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    vi ans;
    int l = -1, r = -1, ind = -1;
    bool flag = true;
    for (int i = 0; i < n; ++i)
    {
        cnt ^= a[i][0];
        for (int j = 0; j < m; ++j)
        {
            if (a[i][0] != a[i][j] && flag)
            {
                l = 0;
                r = j;
                ind = i;
                flag = false;
            }
        }
    }
    if (cnt != 0)
    {
        cout << "TAK" << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << 1 << " ";
        }
        cout << endl;
    }
    else if (!flag)
    {
        cout << "TAK" << endl;
        for (int i = 0; i < n; ++i)
        {
            if (i == ind)
            {
                cout << r + 1 << " ";
            }
            else
            {
                cout << 1 << " ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "NIE" << endl;
    }
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
