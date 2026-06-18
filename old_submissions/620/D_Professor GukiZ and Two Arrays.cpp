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
    int n;
    cin >> n;
    vi a(n);
    int sum1 = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum1 += a[i];
    }
    int m;
    cin >> m;
    vi b(m);
    int sum2 = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
        sum2 += b[i];
    }
    vvi c, d;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            c.push_back({2 * (a[i] + a[j]), i + 1, j + 1});
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = i + 1; j < m; ++j)
        {
            d.push_back({2 * (b[i] + b[j]), i + 1, j + 1});
        }
    }
    int ans = sum1 - sum2;
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    d.push_back({(int) 1e18, -1, -1});
    int anss = abs(ans);
    int in1 = -1, in2 = -1, in3 = -1, in4 = -1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (abs(ans + 2 * b[j] - 2 * a[i]) < anss)
            {
                anss = abs(ans + 2 * b[j] - 2 * a[i]);
                in1 = i + 1;
                in3 = j + 1;
            }
        }
    }
    for (int i = 0; i < c.size(); ++i)
    {
        int ans12 = c[i][0], ind1 = c[i][1], ind2 = c[i][2];
        int k = ans - c[i][0];
        int l = -1, r = d.size() - 1;
        while (r - l > 1)
        {
            int mid = (r + l) / 2;
            if (d[mid][0] + k < 0)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        if (l > -1 && abs(d[l][0] + k) < anss)
        {
            anss = abs(d[l][0] + k);
            in1 = ind1;
            in2 = ind2;
            in3 = d[l][1];
            in4 = d[l][2];
        }
        if (abs(d[r][0] + k) < anss)
        {
            anss = abs(d[r][0] + k);
            in1 = ind1;
            in2 = ind2;
            in3 = d[r][1];
            in4 = d[r][2];
        }
    }
    if (in1 == -1)
    {
        cout << anss << "\n";
        cout << 0 << "\n";
    }
    else if (in2 == -1)
    {
        cout << anss << "\n";
        cout << 1 << "\n";
        cout << in1 << " " << in3 << "\n";
    }
    else
    {
        cout << anss << "\n";
        cout << 2 << "\n";
        cout << in1 << " " << in3 << "\n";
        cout << in2 << " " << in4 << "\n";
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
