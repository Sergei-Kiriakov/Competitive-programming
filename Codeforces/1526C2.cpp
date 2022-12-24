#include <bits/stdc++.h>

#define int long long int

using namespace std;

template <class T>
class Node 
{
public:
    T info;
    T add = 0;

    Node<T> ()
    {
        info = 1e9;
    }

    Node<T> (T _a)
    {
        info = _a;
    }

    Node<T> operator+(Node<T> v)
    {
        return Node<T> (min(info, v.info));
    }
};

template <class T>
class Seg_Tree
{
public:
    vector<Node<T> > tree;
    int n;

    Seg_Tree<T> (vector<T> &a)
    {
        n = a.size();
        tree = vector<Node<T> > (8 * n);
        build(a, 0, n - 1);
    }

    void push (int v)
    {
        tree[v].info += tree[v].add;
        tree[2 * v + 1].add += tree[v].add;
        tree[2 * v + 2].add += tree[v].add;
        tree[v].add = 0;
    }

    void build (vector<T> &a, int tl, int tr, int v = 0) // tl = 0, tr = n - 1, v = 0;
    {
        if (tl == tr)
        {
            tree[v] = Node<T>(a[tl]);
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(a, tl, tm, v * 2 + 1);
            build(a, tm + 1, tr, v * 2 + 2);
            tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
        }
    } 

    Node<T> ask (int l, int r, int tl, int tr, int v = 0) // tl = 0, tr = n - 1, v = 0;
    {
        push(v);
        if (l > r)
        {
            return Node<T>();
        }
        if (tl == l && tr == r)
        {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return ask(l, min(r, tm), tl, tm, v * 2 + 1)
        + ask(max(l, tm + 1), r, tm + 1, tr, v * 2 + 2);
    }

    void update (int l, int r, int new_val, int tl, int tr, int v = 0) // tl = 0, tr = n - 1, v = 0;
    {
        push(v);
        if (l > r)
        {
            return;
        }
        if (l == tl && r == tr)
        {
            tree[v].add += new_val;
            push(v);
        }
        else
        {
            int tm = (tl + tr) / 2;
            update(l, min(r, tm), new_val, tl, tm, v * 2 + 1);
            update(max(l, tm + 1), r, new_val, tm + 1, tr, v * 2 + 2);
            tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
        }
    }
};

int32_t main()
{
    // ifstream cin("sum.in");
    // ofstream cout("sum.out");
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector<int> b(n, 0);
    Seg_Tree<int> A(b);
    int ans = 0; 
    for (int i = 0; i < n; ++i)
    {
        int x = a[i].first, pos = a[i].second;
        A.update(pos, n - 1, x, 0, n - 1, 0);
        if (A.ask(0, n - 1, 0, n - 1, 0).info >= 0)
        {
            ++ans;
        }
        else
        {
            A.update(pos, n - 1, -x, 0, n - 1, 0);
        }
    }
    cout << ans << endl;
}

/*
*/