// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

//#define int long long
//#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

pair<string, string> solve(int n, const vector<string> & need_words, const string & not_needed)
{
    map<int, int> it;
    for (int i = 0; i < n; ++i) {
        it[i] = -1;
    }
    string ans;
    int not_needed_ind = 0;
    vector<int> need_del;
    while (not_needed_ind < not_needed.size()) {
        for (auto & [i, ind] : it) {
            ++ind;
            while (ind < need_words[i].size() and need_words[i][ind] != not_needed[not_needed_ind]) {
                ans += need_words[i][ind];
                ++ind;
            }
            if (ind == need_words[i].size()) {
                need_del.push_back(i);
            }
        }
        for (auto el : need_del) {
            it.erase(el);
        }
        need_del.clear();
        if (it.empty())
            break;
        ans += not_needed[not_needed_ind];
        ++not_needed_ind;
    }
    if (not_needed_ind == not_needed.size()) {
        return {"NO", ""};
    }
    return {"YES", ans};
}

void input()
{
    int n;
    cin >> n;
    vector<string> need_name(n);
    for (int i = 0; i < n; ++i) {
        cin >> need_name[i];
    }
    string not_needed;
    cin >> not_needed;
    pair<string, string> ans = solve(n, need_name, not_needed);
    cout << ans.first << endl;
    if (ans.first == "YES") {
        cout << ans.second << endl;
    }
}

int32_t main()
{
    // ofstream cout("");
    // ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
//    cin >> tt;
    while(tt-->0)
    {
        input();
    }
}

/*
*/