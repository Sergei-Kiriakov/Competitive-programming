//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    map<string, int> best_time, worst_time;
    map<string, int> cnt_problems;
    map<string, int> last_ok;
    vector<string> names;
    for (int i = 0; i < m; ++i)
    {
        string name;
        cin >> name;
        names.push_back(name);
        best_time[name] = 0;
        worst_time[name] = 0;
        cnt_problems[name] = 0;
        last_ok[name] = 0;
        for (int j = 0; j < n; ++j)
        {
            char c;
            int a, t;
            cin >> c >> a >> t;
            if (c == '+')
            {
                last_ok[name] = max(last_ok[name], t);
                best_time[name] += (a - 1) * 20 + t;
                worst_time[name] += (a - 1) * 20 + t;
                ++cnt_problems[name];
            }
            else
            {
                best_time[name] += a * 20 + 240;
            }
        }
    }
    vector<pair<int, pair<int, string> > > res(k);
    set<string> used_names;
    for (int i = 0; i < k; ++i)
    {
        string name;
        cin >> name;
        res[i] = {0, {0, name}};
        used_names.insert(name);
        for (int j = 0; j < n; ++j)
        {
            char c;
            int a, t;
            cin >> c >> a >> t;
            if (c == '+')
            {
                last_ok[name] = max(last_ok[name], t);
                --res[i].first;
                res[i].second.first += (a - 1) * 20 + t;
            }
        }
    }
    sort(all(res));
    int first = 0, finish = k - 1;
    int time_first = res[first].second.first, prob_first = -res[first].first;
    string first_name = res[first].second.second;
    int first_last_ok = last_ok[first_name];
    int time_finish = res[finish].second.first, prob_finish = -res[finish].first;
    string finish_name = res[finish].second.second;
    int finish_last_ok = last_ok[finish_name];
    if (prob_first != n)
    {
        cout << "Leaked" << endl;
        return;
    }
    bool ans = true;
    for (string name : names)
    {
        if (used_names.count(name) != 0)
            continue;
        bool high = false, low = false;
        int tt = last_ok[name];
        if (cnt_problems[name] != n)
            tt = 240;
        if (best_time[name] < time_first or (best_time[name] == time_first and first_last_ok > tt)
        or (best_time[name] == time_first and first_last_ok == tt and name < first_name))
        {
            high = true;
        }
        if (cnt_problems[name] < prob_finish or (cnt_problems[name] == prob_finish and worst_time[name] > time_finish)
        or (cnt_problems[name] == prob_finish and worst_time[name] == time_finish and finish_last_ok < last_ok[name])
        or  (cnt_problems[name] == prob_finish and finish_last_ok == last_ok[name] and worst_time[name] == time_finish
        and name > finish_name))
        {
            low = true;
        }
        if (!low and !high)
            ans = false;
    }
    if (ans)
    {
        cout << "Leaked" << endl;
    }
    else
    {
        cout << "Fake" << endl;
    }
}

int32_t main()
{
//    ofstream cout("sum.out");
//    ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(9);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/  