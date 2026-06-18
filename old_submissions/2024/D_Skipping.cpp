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
    // neutral items for add for propagation
//    int neutral = numeric_limits<int>::min(); // for max operation
    static const int neutral = numeric_limits<int>::max(); // for min operation
//    int neutral = 0; // for sum operation

    type_value operator+ (type_value v) {return min(this, v);}

    struct Node
    {
        // value in nodes
        type_value value;
        type_value add;

        type_value operator+ (type_value v) {return min(this, v);}

        Node () {value = neutral; add = neutral;}
        Node(type_value value_) { value = value_; add = neutral;}
        Node(type_value value_, type_value add_) { value = value_; add = add_;}
        // !!! Change here !!!
        Node operator+(Node v) { return Node(min(value, v.value)); }
        void prop_add(type_value v) {add = min(add, v);}
        void prop_value() {value = min(add, value);}
    };
    // !!! Change here !!!
    vector<Node> tree;
    int size;
    // Propagation
    void Propagation(int v)
    {
        if (v * 2 + 2 < tree.size())
        {
            tree[v * 2 + 1].prop_add(tree[v].add);
            tree[v * 2 + 2].prop_add(tree[v].add);
        }
        tree[v].prop_value();
        tree[v].add = neutral;
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
            tree[v].prop_add(new_val);
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
    // 0 indexing
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> cost(n, 1e18);
    cost[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < b[i]; ++j) {
            cost[j] = min(cost[j], cost[i] + a[i]);
        }
    }
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        ans = max(ans, sum - cost[i]);
    }
    cout << ans << endl;
}

void solve1()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> cost(n, 1e18);
    cost[0] = 0;
    SegmentTree<int> tree(cost);
    for (int i = 0; i < n; ++i) {
        if (b[i] >= i + 1) {
            int d = tree.get(i, i);
            tree.update(i + 1, b[i] - 1, d + a[i]);

        }

    }
//    for (int i = 0; i < n; ++i) {
//        cout << tree.get(i, i) << " ";
//    }
//    cout << endl;
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        ans = max(ans, sum - tree.get(i, i));
    }
    cout << ans << endl;
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
        solve1();
    }
}

/*
*/  