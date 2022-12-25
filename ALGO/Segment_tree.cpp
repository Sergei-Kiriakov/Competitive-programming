template <class T>
class Node 
{
public:
    T info;

    Node<T> ()
    {
        info = 0;
    }

    Node<T> (T _a)
    {
        info = _a;
    }

    Node<T> operator+(Node<T> v)
    {
        return Node<T> (info + v.info);
    }
};

template <class T>
class Seg_Tree
{
public:
    vector<Node<T> > tree;
    int n;

    Seg_Tree (vector<T> &a)
    {
        n = a.size();
        tree = vector<Node<T> > (4 * n);
        build(a, 0, n - 1);
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

    void update (int pos, int new_val, int tl, int tr, int v = 0) // tl = 0, tr = n - 1, v = 0;
    {
        if (tl == tr)
        {
            tree[v] = Node<T>(new_val);
        }
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
            {
                update(pos, new_val, tl, tm, v * 2 + 1);
            }
            else
            {
                update(pos, new_val, tm + 1, tr, v * 2 + 2);
            }
            tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
        }
    }
};

// https://codeforces.com/gym/100249 - для проверки