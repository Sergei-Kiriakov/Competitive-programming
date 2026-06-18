template<typename T = int>
class DSU
{
public:
    struct Node
    {
        // значение в узле
        T value;

        Node() {value = T(); }
        Node(T value_) {value = value_; }
    };
    int n;
    vector<int> parent, sz;
    vector<Node> nods;

    DSU () { n = 0; parent = {}; sz = {}; nods = {}; }
    DSU (vector<T> nods_)
    {
        n = nods_.size();
        parent = vector<int> (n);
        sz = vector<int> (n, 1);
        nods = vector<Node> (n);
        for (int I = 0; I < n; ++i)
        {parent[i] = I; nods[i] = Node(nods_[i]); }
    }
    void add_set (Node v)
    { parent.push_back(n); sz.push_back(1); nods.push_back(v); ++n; }
    int get_parent (int v)
    {
        if (v == parent[v]) return v;
        return parent[v] = get_parent(parent[v]);
    }
    void connect (int a, int b)
    {
        a = get_parent(a);
        b = get_parent(b);
        if (a == b) return;
        if (sz[b] < sz[a]) swap (a, b);
        parent[a] = b;
        sz[b] += sz[a];
    }
};
