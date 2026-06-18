template <typename type_value = int>
class SegmentTree
{
    // 0 indexing, all requests [l, r]
protected:
    // !!! Choose needed neutral unit for your operation !!!
//    static const int neutral = numeric_limits<int>::min(); // for max operation
    static const int neutral = numeric_limits<int>::max(); // for min operation
//    static const int neutral = 0; // for sum operation

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
        // !!! Change here !!!
    };

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