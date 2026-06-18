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
    int n;
    cin >> n;
    vpii x, y;
    vector<tuple<int, int, int, int> > q;
    for (int i = 0; i < n; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x.push_back({x1, -1});
        x.push_back({x2, 1});
        y.push_back({y1, -1});
        y.push_back({y2, 1});
        q.push_back({x1, y1, x2, y2});
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int cnt_x = 0;
    vi ans_x;
    for (int i = 0; i < 2 * n; ++i)
    {
        int x1 = x[i].first, f = x[i].second;
        if (f == -1)
        {
            ++cnt_x;
        }
        else
        {
            --cnt_x;
        }
        if (cnt_x >= n - 1)
        {
            ans_x.push_back(x1);
        }
    }
    int cnt_y = 0;
    vi ans_y;
    for (int i = 0; i < 2 * n; ++i)
    {
        int y1 = y[i].first, f = y[i].second;
        if (f == -1)
        {
            ++cnt_y;
        }
        else
        {
            --cnt_y;
        }
        if (cnt_y >= n - 1)
        {
            ans_y.push_back(y1);
        }
    }
    pii ans = {-1, -1};
    for (int xx : ans_x)
    {
        //cout << xx << " ";
        for (int yy : ans_y)
        {
            //cout << yy << endl;
            int cnt = 0;
            for (auto temp : q)
            {
                int x1, y1, x2, y2;
                tie(x1, y1, x2, y2) = temp;
                if (xx >= x1 && xx <= x2 && yy >= y1 && yy <= y2)
                {
                    ++cnt;
                }
            }
            if (cnt >= n - 1)
            {
                ans = {xx, yy};
            }
        }
    }
    cout << ans.first << " " << ans.second << endl;
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
