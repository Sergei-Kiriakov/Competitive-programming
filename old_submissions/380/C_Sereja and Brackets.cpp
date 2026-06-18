#include <bits/stdc++.h>

#define int long long

using namespace std;

constexpr int mod = 998244353;

class Node 
{
public:
    int a, b, c; // длина псп, кол-во открытых скобок вне, кол-во закрытых вне

    Node ()
    {
        a = 0; b = 0; c = 0;
    }

    Node (int a1, int a2, int a3)
    {
        a = a1; b = a2; c = a3;
    }

    Node (char s)
    {
        if (s == '(')
        {
            a = 0; b = 1; c = 0;
        }
        else
        {
            a = 0; b = 0; c = 1;
        }
    }

    Node operator+(Node v)
    {
        int t = min(b, v.c);
        int a1, b1, c1;
        a1 = a + v.a + t;
        b1 = b + v.b - t;
        c1 = c + v.c - t;
        return Node(a1, b1, c1);
    }
};

class Seg_Tree
{
public:
    int n;
    vector<Node> tree;

    Seg_Tree (vector<Node>& a)
    {
        int n = a.size();
        tree = vector<Node> (4 * n);
        build(a, 0, 0, n - 1);
    }

    void build (vector<Node> &a, int v, int tl, int tr) 
    {
        if (tl == tr)
        {
            tree[v] = a[tl];
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(a, v * 2 + 1, tl, tm);
            build(a, v * 2 + 2, tm + 1, tr);
            tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
        }
    } 

    Node ask (int v, int tl, int tr, int l, int r)
    {
        if (l > r)
        {
            return Node();
        }
        if (tl == l && tr == r)
        {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return ask(v * 2 + 1, tl, tm, l, min(r, tm)) 
        + ask(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r);
    }

    void update (int v, int tl, int tr, int pos, int new_val)
    {
        if (tl == tr)
        {
            tree[v] = new_val;
        }
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
            {
                update(v * 2 + 1, tl, tm, pos, new_val);
            }
            else
            {
                update(v * 2 + 2, tm + 1, tr, pos, new_val);
            }
            tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
        }
    }
};

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<Node> a(n);
    for (int i = 0; i < n; ++i)
    {
        a[i] = Node(s[i]);
    }
    Seg_Tree A(a);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        cout << A.ask(0, 0, n - 1, l, r).a * 2 << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
}

/*

*/