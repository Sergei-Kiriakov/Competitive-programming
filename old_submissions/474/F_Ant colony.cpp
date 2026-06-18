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
class SegmentTreeGcd
{
protected:
    struct Node
    {
        type_value value;

        Node () {value = type_value(); }
        Node(type_value value_) { value = value_; }
        Node operator+(Node v) { return Node(__gcd(value, v.value)); }
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
public:
    SegmentTreeGcd (vector<type_value> &a)
    {
        size = a.size();
        tree = vector<Node> (4 * size);
        build(a, 0, size - 1);
    }

    type_value get(int l, int r)
    {
        return Get(l, r, 0, size - 1, 0).value;
    }
};

template <typename type_value = int>
class SegmentTreeMin
{
protected:
    struct Node
    {
        type_value value;
        int cnt = 0;

        Node () {value = type_value(); cnt = 1; }
        Node(type_value value_) { value = value_; cnt = 1; }
        Node(type_value value_, int cnt_) { value = value_; cnt = cnt_; }
        Node operator+(Node v)
        {
            if (value < v.value)
            {
                return Node(value, cnt);
            }
            else if (value == v.value)
            {
                return Node(value, cnt + v.cnt);
            }
            return Node(v.value, v.cnt);
        }
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
public:
    SegmentTreeMin (vector<type_value> &a)
    {
        size = a.size();
        tree = vector<Node> (4 * size);
        build(a, 0, size - 1);
    }

    Node get(int l, int r)
    {
        return Get(l, r, 0, size - 1, 0);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    SegmentTreeGcd<int> seg_gcd(a);
    SegmentTreeMin<int> seg_min(a);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l; --r;
        auto temp = seg_min.get(l, r);
        int min1 = temp.value, cnt = temp.cnt;
        int gcd = seg_gcd.get(l, r);
        if (gcd % min1 == 0)
            cout << r - l + 1 - cnt << endl;
        else
            cout << r - l + 1 << endl;
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