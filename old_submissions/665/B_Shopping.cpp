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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(k);
    vi cnt(k + 1);
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
        cnt[a[i]] = i + 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int x;
            cin >> x;
            ans += cnt[x];
            for (int l = cnt[x] - 1; l > 0; --l)
            {
                a[l] = a[l - 1];
                cnt[a[l - 1]] = l + 1;
            }
            a[0] = x;
            cnt[x] = 1;
            /*
            for (int l = 0; l < k; ++l)
            {
                cout << a[l] << " ";
            }
            cout << "\n";
            */
        }
    }
    cout << ans << "\n";
}

/*
5
1 2 3 4 5
1 3
2 3
*/
