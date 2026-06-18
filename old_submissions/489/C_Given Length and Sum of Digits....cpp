#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179;

void solve()
{
    int m, s;
    cin >> m >> s;
    vi max1(m, 0), min1(m, 0);
    max1[0] = 1;
    min1[0] = 1;
    --s;
    if (m == 1 && s == -1)
    {
        cout << 0 << " " << 0 << "\n";
    }
    else if (s < 0)
    {
        cout << -1 << " " << -1 << "\n";
    }
    else
    {
        int s1 = s;
        for (int i = 0; i < m; ++i)
        {
            int dif = min(abs(max1[i] - 9), s1);
            s1 -= dif;
            max1[i] += dif;
        }
        int s2 = s;
        for (int i = m - 1; i > -1; --i)
        {
            int dif = min(abs(min1[i] - 9), s2);
            s2 -= dif;
            min1[i] += dif;
        }
        if (s1 != 0 || s2 != 0)
        {
            cout << -1 << " " << -1 << "\n";
        }
        else
        {
            for (int i = 0; i < m; ++i)
            {
                cout << min1[i];
            }
            cout << " ";
            for (int i = 0; i < m; ++i)
            {
                cout << max1[i];
            }
            cout << "\n";
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
    //solve();
    return 0;
}
