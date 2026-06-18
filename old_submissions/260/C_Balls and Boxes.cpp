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
    int n, x;
    cin >> n >> x;
    --x;
    vi a(n);
    int min1 = 1e9;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        min1 = min(min1, a[i]);
    }
    int j = x;
    while (j != (x + 1) % n && a[j] != min1)
    {
        j = (j - 1 + n) % n;
    }
    int j1 = j;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        int k = (j + i) % n;
        a[k] -= min1;
        cnt += min1;
    }
    if (j1 != x)
    {
        j = (j + 1) % n;
        while (j != x)
        {
            --a[j];
            ++cnt;
            j = (j + 1) % n;
        }
        --a[j];
        ++cnt;
    }
    for (int i = 0; i < n; ++i)
    {
        if (i != j1)
            cout << a[i] << " ";
        else
            cout << cnt << " ";
    }
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
