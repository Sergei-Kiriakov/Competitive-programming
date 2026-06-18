#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179, MAX = 1e4 * 4;

void solve()
{
    int start, finish;
    cin >> start >> finish;
    vi d(MAX, 1e9);
    d[start] = 0;
    deque<int> q;
    q.push_back(start);
    while (!q.empty())
    {
        int now = q.front();
        q.pop_front();
        if (now - 1 > -1 && d[now - 1] > d[now] + 1)
        {
            d[now - 1] = d[now] + 1;
            q.push_back(now - 1);
        }
        if (now * 2 < MAX && d[now * 2] > d[now] + 1)
        {
            d[now * 2] = d[now] + 1;
            q.push_back(now * 2);
        }
    }
    cout << d[finish] << "\n";
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
