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
    int n, t, r;
    cin >> n >> t >> r;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    deque<int> events;
    if (t < r)
    {
        cout << -1 << endl;
    }
    else
    {
        int cnt = 0, ans = 0;
        int j = 0;
        for (int i = 0; i < 301; ++i)
        {
            if (j < n && a[j] == i)
            {
                ++j;
                for (int k = r - cnt; k > 0; --k)
                {
                    ++cnt;
                    ++ans;
                    events.push_back(i - k + t);
                }
            }
            if (events.size() > 0 && events.front() == i)
            {
                --cnt;
                events.pop_front();
            }
        }
        cout << ans << endl;
    }


}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
