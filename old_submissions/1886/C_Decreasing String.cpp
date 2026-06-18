//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

template <typename type_value = int>
class SegmentTree
{
protected:
    struct Node
    {
        type_value value;
        int ind;

        Node () {value = type_value(); ind = 0; }
        Node(type_value value_) { value = value_; }
        Node(type_value value_, int ind_) {value = value_; ind = ind_; }
        Node operator+(Node v)
        {
            if (value <= v.value)
            {
                return Node(value, ind);
            }
            return Node(v.value, v.ind);
        }
    };
    vector<Node> tree;
    int size;

    void build (vector<type_value> &a, int tl, int tr, int v = 0)
    {
        if (tl == tr)
        {
            tree[v] = Node(a[tl], tl);
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
            tree[v] = Node(new_val, pos);
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

    type_value get(int l, int r)
    {
        return Get(l, r, 0, size - 1, 0).ind;
    }
    void update (int pos, type_value new_val)
    {
        Update(pos, new_val, 0, size - 1, 0);
    }
};

int f (int k, int n)
{
    return k * n - k * (k - 1) / 2;
}

vector<int> ans, a;
vector<int> big(1e6 + 6, 0);
SegmentTree<int> seg(big);
int tic;

void get_ans (int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        ans[l] = tic;
        ++tic;
        return;
    }
    int mid = seg.get(l, r);
    get_ans(l, mid - 1);
    get_ans(mid + 1, r);
    ans[mid] = tic;
    ++tic;
}


void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int pos;
    cin >> pos;
    --pos;
    int k = 0;
    while (f(k + 1, n) <= pos)
    {
        ++k;
    }
    pos -= f(k, n);
//    pos = max(0ll, pos);
    ans = vector<int> (n, 0);
    a = vector<int> (n);
    tic = 1;
    for (int i = 0; i < n; ++i)
    {
        a[i] = s[i];
        seg.update(i, a[i]);
    }
    get_ans(0, n - 1);
    string s1;
    for (int i = 0; i < n; ++i)
    {
        if (ans[i] > k)
            s1.push_back(s[i]);
    }
    cout << s1[pos];
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
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/