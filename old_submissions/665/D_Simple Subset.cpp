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

constexpr int mod = 1e9 + 7, p = 179, MAXN = 1e7 + 1;

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    vb prime(MAXN, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= MAXN; ++i)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                prime[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    vi anss;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (prime[a[i] + a[j]])
            {
                ans = 2;
                anss = {a[i], a[j]};
            }
        }
    }
    if (a[0] == 1)
    {
        int j = 0;
        vi c = {};
        for (; j < n && a[j] == 1; ++j)
        {
            c.push_back(1);
        }
        for (int i = j; i < n; ++i)
        {
            if (prime[a[i] + 1])
            {
                //cerr << a[i] << "\n";
                c.push_back(a[i]);
                ++j;
                break;
            }
        }
        if (j > ans)
        {
            ans = j;
            anss = c;
        }
    }
    if (ans == 0)
    {
        ans = 1;
        anss = {a[0]};
    }
    cout << ans << "\n";
    for (int i = 0; i < ans; ++i)
    {
        cout << anss[i] << " ";
    }
    cout << "\n";
}

/*
5
1 2 3 4 5
1 3
2 3
*/
