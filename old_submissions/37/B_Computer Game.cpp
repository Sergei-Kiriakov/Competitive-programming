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
    int n, max_hp, reg;
    cin >> n >> max_hp >> reg;
    vector<tuple<int, int, int> > d;
    vpii ans;
    int hp = max_hp;
    int t = 0;
    for (int i = 0; i < n; ++i)
    {
        int pow, dmg;
        cin >> pow >> dmg;
        int k = (max_hp * pow) / 100;
        d.push_back({k, dmg, i});
    }
    sort(d.begin(), d.end());
    set<pair<int, int> > s;
    while (hp > 0)
    {
        bool flag = true;
        while (d.size() != 0 && hp <= get<0>(d.back()))
        {
            int k, dmg, ind;
            tie(k, dmg, ind) = d.back();
            s.insert({dmg, ind});
            d.pop_back();
        }
        if (s.size() != 0)
        {
            pii temp = *(--s.end());
            s.erase(--s.end());
            int dmg = temp.first, ind = temp.second;
            reg -= dmg;
            ans.push_back({t, ind + 1});
            flag = false;
        }
        if (flag && reg >= 0)
        {
            break;
        }
        hp = min(max_hp, hp + reg);
        ++t;
    }
    if (hp > 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << t << " " << ans.size() << endl;
        for (int i = 0; i < ans.size(); ++i)
        {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
