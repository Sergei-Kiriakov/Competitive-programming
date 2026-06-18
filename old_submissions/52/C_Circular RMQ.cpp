#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

template <typename type_value = int>
class SegmentTree
{
protected:
    struct Node
    {
        type_value value;
        type_value add;

        Node () {value = 1e18; add = type_value(); }
        Node(type_value value_) { value = value_; add = type_value(); }
        Node(type_value value_, type_value add_)
        {
            value = value_;
            add = add_;
        }
        Node operator+(Node v) { return Node(min(value, v.value)); }
    };
    vector<Node> tree;
    int size;

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
        if (tl == l && tr == r)
        {
            tree[v].add += new_val;
            Propagation(v);
            return;
        }
        int tm = (tl + tr) / 2;
        if (l <= tm && tm + 1 <= r)
        {
            Update(l, tm, new_val, tl, tm, v * 2 + 1);
            Update(tm + 1, r, new_val, tm + 1, tr, v * 2 + 2);
        }
        else if (l <= tm) Update(l, r, new_val, tl, tm, v * 2 + 1);
        else if (tm + 1 <= r) Update(l, r, new_val, tm + 1, tr, v * 2 + 2);
        Propagation(v * 2 + 1);
        Propagation(v * 2 + 2);
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

void f(string s, int& l, int& r, int& v)
{
    vector<int> a = {0};
    int n = s.size();
    bool minus = false;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == ' ')
        {
            if (minus)
                a.back() *= -1;
            minus = false;
            a.push_back(0);
        }
        else if (s[i] == '-')
        {
            minus = true;
        }
        else
        {
            a.back() *= 10;
            a.back() += s[i] - '0';
        }
    }
    if (minus)
        a.back() *= -1;
    l = a[0];
    r = a[1];
    if (a.size() == 3)
    {
        v = a[2]; 
    }
}

int32_t main()
{
    // ofstream cout("sum.out");
    // ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    SegmentTree<int> tree(a);
    int m;
    cin >> m;
    string s1;
    getline(cin, s1);
    for (int i = 0; i < m; ++i)
    {
        string s;
        getline(cin, s);
        int l, r, v = 1e9;
        f(s, l, r, v);
        if (i == 41)
            int p = 3;
        if (v == 1e9)
        {
            if (l > r)
            {
                cout << min(tree.get(0, r), tree.get(l, n - 1)) << endl;
            }
            else
            {
                cout << tree.get(l, r) << endl;
            }
        }
        else
        {
            if (l > r)
            {
                tree.update(0, r, v);
                tree.update(l, n - 1, v);
            }
            else
            {
                tree.update(l, r, v);
            }
        }
    }
}


/*
4
0 -1 0 -1
49
3 1 -1
1 1 0
1 3
2 2
2 2 1
2 2
1 2
0 2 1
1 1 0
1 3 -1
0 1 1
1 1 1
0 1 0
1 3
1 2
1 2 0
3 0 0
3 3
2 3
2 3 0
3 0
3 0
1 1 0
2 0
0 0 -1
1 1
2 2
0 1
1 2
2 2
0 1
2 0 0
0 2
3 3
0 2 -1
0 1
3 0 -1
3 1 -1
2 2 -1
3 0
3 0
2 0 1
0 0 0
1 1 -1
0 2 0
0 0
1 1
1 1 1
2 3
*/  