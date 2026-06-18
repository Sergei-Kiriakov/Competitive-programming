//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod1 = 1e9 + 93, mod2 = 1e9 + 21, d = 179;

template <typename type_value = int>
class SegmentTree
{
protected:
    struct Node
    {
        vector<int> bits;
        type_value add;

        Node () {add = type_value(); bits = vector<int> (20, 0); }
        Node(type_value n)
        {
            add = 0;
            bits = vector<int> (20, 0);
            for (int i = 0; i < bits.size(); ++i)
            {
                if (n & (1 << i))
                    bits[i] = 1;
            }
        }
        Node(type_value add_, vector<int> bits_) {{ add = add_; bits = bits_; }}
        Node operator+(Node v)
        {
            vector<int> bits_(20, 0);
            for (int i = 0; i < bits_.size(); ++i) bits_[i] = bits[i] + v.bits[i];
            return Node(add, bits_);
        }
    };
    vector<Node> tree;
    int size;

    void Propagation(int v, int l, int r)
    {
        int sz = r - l + 1;
        if (v * 2 + 2 < tree.size())
        {
            tree[v * 2 + 1].add ^= tree[v].add;
            tree[v * 2 + 2].add ^= tree[v].add;
        }
        for (int i = 0; i < tree[v].bits.size(); ++i)
            if (tree[v].add & (1 << i))
                tree[v].bits[i] = sz - tree[v].bits[i];
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
        Propagation(v, tl, tr);
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
        Propagation(v, tl, tr);
        if (l > r) return;
        if (tl == l && tr == r)
        {
            tree[v].add ^= new_val;
            Propagation(v, tl, tr);
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
    type_value get(int l, int r)
    {
        vector<int> bits_ = Get(l, r, 0, size - 1, 0).bits;
        int ans = 0;
        for (int i = 0; i < bits_.size(); ++i)
        {
            ans += bits_[i] * (1 << i);
        }
        return ans;
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    SegmentTree<int> seg(a);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int ask;
        cin >> ask;
        if (ask == 1)
        {
            int l, r;
            cin >> l >> r;
            --l; --r;
            cout << seg.get(l, r) << endl;
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x;
            --l; --r;
            seg.update(l, r, x);
        }
    }
}

int32_t main()
{
//    ofstream cout("sum.out");

    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(6);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
3 9 9 2
0 0 1
1 0 2
2 0 5
3 0 10
1 1 3
1 2 4
2 2 7
0 5 6
7 7 57
5 5
-4 3
*/