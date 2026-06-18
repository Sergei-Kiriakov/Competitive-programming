#include <bits/stdc++.h>
//#define int long long

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

constexpr int mod = 998244353, p = 179;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n, m;
    cin >> n >> m;
    vpii a, b;
    for (int i = 0; i < m; ++i)
    {
        int v, d;
        cin >> v >> d;
        if (d == 0)
        {
            b.push_back({v, i});
        }
        else
        {
            a.push_back({v, i});
        }
    }
    vpii ans(m);
    bool er = false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    set<pii> s;
    for (int i = 0; i < n - 1; ++i)
    {
        ans[a[i].second] = {i + 1, i + 2};
        s.insert({a[i].first, i});
    }
    vvi tree (n);
    for (int i = 0; i < b.size(); ++i)
    {
        int w = b[i].first, ind = b[i].second;
        auto it = lower_bound(s.begin(), s.end(), make_pair(w, mod));
        if (it == s.begin())
        {
            er = true;
        }
        else
        {
            --it;
            int temp = (*it).second;
            if (tree[temp + 1].size() == temp)
            {
                er = true;
            }
            else
            {
                tree[temp + 1].push_back(ind);
                if (tree[temp + 1].size() == temp)
                {
                    s.erase(it);
                }
            }

        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < tree[i].size(); ++j)
        {
            int ind = tree[i][j];
            ans[ind] = {i + 1, i - j - 1};
        }
    }
    if (er)
    {
        cout << -1 << endl;
    }
    else
    {
        for (pii u : ans)
        {
            cout << u.first << " " << u.second << endl;
        }
    }
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
