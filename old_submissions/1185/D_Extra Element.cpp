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

int f (vpii a, int c, int b, int m)
{
    int cnt = 0, ans = a[0].second;
    int n = a.size();
    for (int i = 0; i < n; ++i)
    {
        if (a[i].first != b + c * (i - cnt))
        {
            ++cnt;
            ans = a[i].second;
        }
    }
    if (cnt > m)
    {
        return -1;
    }
    return ans + 1;
}

vpii copyy(vpii a, int j)
{
    int n = a.size();
    vpii ans;
    for (int i = 0; i < n; ++i)
    {
        if (i != j)
            ans.push_back(a[i]);
    }
    return ans;
}

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n;
    cin >> n;
    vpii b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b.begin(), b.end());
    if (n == 2)
    {
        cout << 1;
    }
    else
    {
        int ans1 = f(copyy(b, 1e9), b[1].first - b[0].first, b[0].first, 1);
        int ans2 = f(copyy(b, 1), b[2].first - b[0].first, b[0].first, 0);
        int ans3 = f(copyy(b, 0), b[2].first - b[1].first, b[1].first, 0);
        if (ans1 != -1)
        {
            cout << ans1 << endl;
        }
        else if (ans2 != -1)
        {
            cout << b[1].second + 1 << endl;
        }
        else if (ans3 != -1)
        {
            cout << b[0].second + 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
