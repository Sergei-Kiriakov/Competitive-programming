#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

//#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()


using namespace std;

const int mod = 1e9 + 7, kk = 26;

int ans = 0;

struct Vertex {
    Vertex* to[kk] = {0};
    bool terminal = 0;
    int cnt = 0;
};

Vertex *root = new Vertex();

void add_string(string &s) {
    Vertex* v = root;
    ++v->cnt;
    for (char c : s) {
        c -= 'a';
        if (!v->to[c])
        {
            v->to[c] = new Vertex();
        }
        v = v->to[c];
        ++v->cnt;
    }
    v->terminal = true;
}

bool cmp(pair<int, Vertex*> a, pair<int, Vertex*> b)
{
    return a.first > b.first;
}

int get_ans(Vertex* v, int k)
{
    if (v->cnt <= k)
    {
        ++ans;
        int ff = v->cnt;
        v->cnt = 0;
        return ff;
    }
    int sum_del = 0;
    while (true)
    {
        vector<pair<int, Vertex*>> a;
        for (int i = 0; i < kk; ++i)
        {
            Vertex* w = v->to[i];
            if (w != NULL)
            {
                a.push_back({w->cnt, w});
            }
        }
        sort(a.begin(), a.end(), cmp);
        int dd = get_ans(a[0].second, k);
        v->cnt -= dd;
        sum_del += dd;
        if (v->cnt <= k)
        {
            return sum_del;
        }
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        add_string(s);
    }
    if (n != get_ans(root, k))
        ++ans;
    cout << ans << endl;
}

int32_t main()
{
    //ofstream cout("sum.out");
    //ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    //cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/