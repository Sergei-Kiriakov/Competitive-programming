//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define remin(x, y) x = min(x, y)
#define remax(x, y) x = max(x, y)
#define lowpos(a, x) int(lower_bound(a.begin(), a.end(), x) - a.begin())
#define uppos(a, x) int(upper_bound(a.begin(), a.end(), x) - a.begin())

using namespace std;

constexpr int mod = 1e9 + 7;

template <typename type_value = int>
class SegmentTreeMax
{
protected:
    struct Node
    {
        // Значения в узлах
        type_value value;
        int ind;
        type_value add;

        Node () {value = type_value(); add = type_value(); ind = -1;}
        Node(type_value value_) { value = value_; add = type_value(); ind = -1;}
        Node(type_value value_, int ind_) { value = value_; add = 0; ind = ind_;}
        // Основная операция
        Node operator+(Node v)
        {
            if (v.value > value)
                return Node(v.value, v.ind);
            return Node(value, ind);
        }
    };

    vector<Node> tree;
    int size;

    // Проталкивание
    void Propagation(int v)
    {
        if (v * 2 + 2 < tree.size())
        {
            tree[v * 2 + 1].add += tree[v].add;
            tree[v * 2 + 2].add += tree[v].add;
        }
        tree[v].value += tree[v].add;
        tree[v].add = type_value();
    }
    void build (vector<type_value> &a, int tl, int tr, int v = 0)
    {
        if (tl == tr)
        {
            tree[v] = Node(a[tl], tl);
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, tl, tm, v * 2 + 1);
        build(a, tm + 1, tr, v * 2 + 2);
        tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
    }
    Node Get (int l, int r, int tl, int tr, int v)
    {
        Propagation(v);
        if (tl == l && tr == r)
            return tree[v];
        int tm = (tl + tr) / 2;
        Node ans;
        if (l <= tm && tm + 1 <= r)
            return Get(l, tm, tl, tm, v * 2 + 1) +
                   Get(tm + 1, r, tm + 1, tr, v * 2 + 2);
        if (l <= tm) return Get(l, r, tl, tm, v * 2 + 1);
        if (tm + 1 <= r) return Get(l, r, tm + 1, tr, v * 2 + 2);
    }
    void Update (int l, int r, type_value new_val, int tl, int tr, int v)
    {
        Propagation(v);
        if (l > r) return;
        if (tl == l && tr == r)
        {
            tree[v].value = new_val;
            Propagation(v);
            return;
        }
        int tm = (tl + tr) / 2;
        Update(l, min(r, tm), new_val, tl, tm, v * 2 + 1);
        Update(max(tm + 1, l), r, new_val, tm + 1, tr, v * 2 + 2);
        tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
    }
public:
    SegmentTreeMax (vector<type_value> &a)
    {
        size = a.size();
        tree = vector<Node> (4 * size);
        build(a, 0, size - 1);
    }
    // 0 индексация
    type_value get(int l, int r)
    {
        return Get(l, r, 0, size - 1, 0).ind;
    }
    void update (int pos, type_value new_val)
    {
        Update(pos, pos, new_val, 0, size - 1, 0);
    }
    void update (int l, int r, type_value new_val)
    {
        Update(l, r, new_val, 0, size - 1, 0);
    }
};

template <typename type_value = int>
class SegmentTree
{
protected:
    struct Node
    {
        // Значения в узлах
        type_value value;
        type_value add;

        Node () {value = type_value(); add = type_value(); }
        Node(type_value value_) { value = value_; add = type_value(); }
        Node(type_value value_, type_value add_) { value = value_; add = add_; }
        // Основная операция
        Node operator+(Node v) { return Node(value + v.value); }
    };

    vector<Node> tree;
    int size;

    // Проталкивание
    void Propagation(int v)
    {
        if (v * 2 + 2 < tree.size())
        {
            tree[v * 2 + 1].add += tree[v].add;
            tree[v * 2 + 2].add += tree[v].add;
        }
        tree[v].value += tree[v].add;
        tree[v].add = type_value();
    }
    void build (vector<type_value> &a, int tl, int tr, int v = 0)
    {
        if (tl == tr)
        {
            tree[v] = Node(a[tl]);
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, tl, tm, v * 2 + 1);
        build(a, tm + 1, tr, v * 2 + 2);
        tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
    }
    Node Get (int l, int r, int tl, int tr, int v)
    {
        Propagation(v);
        if (tl == l && tr == r)
            return tree[v];
        int tm = (tl + tr) / 2;
        Node ans;
        if (l <= tm && tm + 1 <= r)
            return Get(l, tm, tl, tm, v * 2 + 1) +
                   Get(tm + 1, r, tm + 1, tr, v * 2 + 2);
        if (l <= tm) return Get(l, r, tl, tm, v * 2 + 1);
        if (tm + 1 <= r) return Get(l, r, tm + 1, tr, v * 2 + 2);
    }
    void Update (int l, int r, type_value new_val, int tl, int tr, int v)
    {
        Propagation(v);
        if (l > r) return;
        if (tl == l && tr == r)
        {
            tree[v].add += new_val;
            Propagation(v);
            return;
        }
        int tm = (tl + tr) / 2;
        Update(l, min(r, tm), new_val, tl, tm, v * 2 + 1);
        Update(max(tm + 1, l), r, new_val, tm + 1, tr, v * 2 + 2);
        tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
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
        Update(pos, pos, new_val, 0, size - 1, 0);
    }
    void update (int l, int r, type_value new_val)
    {
        Update(l, r, new_val, 0, size - 1, 0);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    SegmentTree<int> t(a);
    SegmentTreeMax<int> t_max(a);
    for (int i = 0; i < m; ++i)
    {
        int ask; cin >> ask;
        if (ask == 1)
        {
            int l, r; cin >> l >> r;
            --l; --r;
            cout << t.get(l, r) << endl;
        }
        else if (ask == 2)
        {
            int l, r, x; cin >> l >> r >> x;
            --l; --r;
            int now = t_max.get(l, r);
            while (a[now] >= x)
            {
                t.update(now, a[now] % x - a[now]);
                a[now] %= x;
                t_max.update(now, a[now]);
                now = t_max.get(l, r);
            }
        }
        else
        {
            int k, x; cin >> k >> x;
            --k;
            t.update(k, x - a[k]);
            t_max.update(k, x);
            a[k] = x;
        }
    }
    return;
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
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