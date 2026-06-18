//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

template <typename type_value = int>
class SegmentTree
{
protected:
    struct Node
    {
        // Значение в узле
        type_value value;

        Node () {value = type_value(); }
        Node(type_value value_) { value = value_; }
        // Тут основная операция
        Node operator+(Node v) { return Node(max(value, v.value)); }
    };
    vector<Node> tree;
    int size;

    void build (vector<type_value> &a, int tl, int tr, int v = 0)
    {
        if (tl == tr)
        {
            tree[v] = Node(a[tl]);
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(a, tl, tm, v * 2 + 1);
            build(a, tm + 1, tr, v * 2 + 2);
            tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
        }
    }
    Node Get (int l, int r, int tl, int tr, int v)
    {
        if (tl == l && tr == r)
        {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        Node ans;
        if (l <= tm && tm + 1 <= r)
            return Get(l, tm, tl, tm, v * 2 + 1) +
                   Get(tm + 1, r, tm + 1, tr, v * 2 + 2);
        if (l <= tm) return Get(l, r, tl, tm, v * 2 + 1);
        if (tm + 1 <= r) return Get(l, r, tm + 1, tr, v * 2 + 2);
    }
    void Update (int pos, type_value new_val, int tl, int tr, int v)
    {
        if (tl == tr)
            tree[v] = Node(max(new_val, tree[v].value));
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                Update(pos, new_val, tl, tm, v * 2 + 1);
            else
                Update(pos, new_val, tm + 1, tr, v * 2 + 2);
            tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
        }
    }
public:
    SegmentTree (vector<type_value> &a)
    {
        size = a.size();
        tree = vector<Node> (4 * size);
        build(a, 0, size - 1);
    }
    // 0 индексация
    type_value get(int l, int r)
    {
        return Get(l, r, 0, size - 1, 0).value;
    }
    void update (int pos, type_value new_val)
    {
        Update(pos, new_val, 0, size - 1, 0);
    }
};

vector<int> solve(const vector<int> &a)
{
    int n = a.size();
    vector<int> max_pr(n);
    vector<int> min_pr(n);
    max_pr[0] = a[0];
    min_pr[n - 1] = 1e9;
    for (int i = 1; i < n; ++i) {
        max_pr[i] = max(max_pr[i - 1], a[i]);
    }
    for (int i = n - 2; i > -1; --i) {
        min_pr[i] = min(min_pr[i + 1], a[i + 1]);
    }
    vector<int> ans(n);
    ans[n - 1] = max_pr[n - 1];
    for (int i = n - 2; i > -1; --i) {
        if (max_pr[i] > min_pr[i]) {
            ans[i] = ans[i + 1];
        }
        else {
            ans[i] = max_pr[i];
        }
    }
    return ans;
}

int32_t main()
{
//    ofstream cout("");
//    ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
//            --a[i];
        }
//        vector<int> temp = solve(a);
        vector<int> ans = solve(a);
        for (auto el : ans) {
            cout << el << " ";
        }
        cout << endl;
    }
}

/*
*/  