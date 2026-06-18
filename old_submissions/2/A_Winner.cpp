#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179, MAX = 1e4 * 4;

void solve()
{
    int n;
    cin >> n;
    vector<pair<string, int> > data(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i].first >> data[i].second;
    }
    map<string, int> scorelist;
    for (int i = 0; i < n; ++i)
    {
        string name = data[i].first;
        int score = data[i].second;
        scorelist[name] += score;
    }
    set<string> win_list;
    int max_score = 0;
    for (pair<string, int> elem : scorelist)
    {
        string name = elem.first;
        int score = elem.second;
        if (max_score < score)
        {
            max_score = score;
            win_list.clear();
        }
        if (max_score == score)
        {
            win_list.insert(name);
        }
    }
    string ans = "";
    scorelist.clear();
    for (int i = 0; i < n; ++i)
    {
        string name = data[i].first;
        int score = data[i].second;
        scorelist[name] += score;
        if (win_list.count(name) && scorelist[name] >= max_score && ans == "")
        {
            ans = name;
        }
    }
    cout << ans << "\n";
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    /*
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    */
    solve();
    return 0;
}
