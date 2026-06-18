#include <functional>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <bitset>
#include <random>
#include <chrono>
#include <cassert>
#include <memory>

using namespace std;

#define long long long

long binPow(long a, long p, long M)
{
    if (p < 0)
        return 0;

    if (p == 0)
        return 1;

    if (p == 1)
        return a % M;

    if (p % 2 == 0)
    {
        long v = binPow(a, p / 2, M);

        return v * v % M;
    }
    else
    {
        long v = binPow(a, p / 2, M);

        return (v * v % M) * a % M;
    }
}

struct DSU {
    vector<long> par, sz;
    DSU(int n) : par(n), sz(n, 1)
    {
        for (int i = 0; i < n; i++)
            par[i] = i;
    }
    int getPar(int u) {
        return par[u] == u ? u : par[u] = getPar(par[u]);
    }
    void connect(int u, int v) {
        u = getPar(u);
        v = getPar(v);
        if (u == v) return;
        if (sz[u] < sz[v]) std::swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
    }
    bool isConnected(int u, int v) {
        return getPar(u) == getPar(v);
    }
}; // class DSU

long inv(long a, long M)
{
    return (M - a) % M;
}

long gcd(long a, long b)
{
    while (a != 0 && b != 0)
    {
        if (a >= b)
            a %= b;
        else b %= a;
    }

    return a + b;
}

long lcm(long a, long b)
{
    return a * b / gcd(a, b);
}

class LCA
{
private:
    int n, l;
    vector<vector<pair<long, long>>> adj;

    int timer;
    vector<int> tin, tout;
    vector<vector<pair<long, long>>> up;

    void dfs(int v, int p, long e)
    {
        tin[v] = ++timer;
        up[v][0].first = p;
        up[v][0].second = e;

        for (int i = 1; i <= l; ++i)
        {
            up[v][i].first = up[up[v][i - 1].first][i - 1].first;
            up[v][i].second = max(up[up[v][i - 1].first][i - 1].second, up[v][i - 1].second);
        }

        for (auto& u : adj[v]) {
            if (u.first != p)
                dfs(u.first, v, u.second);
        }

        tout[v] = ++timer;
    }

    void preprocess(int root) {
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<pair<long, long>>(l + 1));
        dfs(root, root, 0);
    }

public:
    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i].first, v))
                u = up[u][i].first;
        }
        return up[u][0].first;
    }

    long getMax(long u, long v)
    {
        long lc = lca(u, v);
        long h = l;

        long ans = 0;

        for (int i = h; i >= 0; --i) {
            if (is_ancestor(lc, up[u][i].first))
            {
                ans = max(ans, up[u][i].second);
                u = up[u][i].first;
            }
        }

        for (int i = h; i >= 0; --i) {
            if (is_ancestor(lc, up[v][i].first))
            {
                ans = max(ans, up[v][i].second);
                v = up[v][i].first;
            }
        }

        return ans;
    }

    LCA(long N, long root, vector<vector<pair<long, long>>>& g)
    {
        n = N;
        adj = g;

        preprocess(root);
    }
};

long phi(long n) {
    long result = n;
    for (long i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}

struct TwoSatSolver {
    int n_vars;
    int n_vertices;
    vector<vector<int>> adj, adj_t;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;

    TwoSatSolver(int _n_vars) : n_vars(_n_vars), n_vertices(2 * n_vars), adj(n_vertices), adj_t(n_vertices), used(n_vertices), order(), comp(n_vertices, -1), assignment(n_vars) {
        order.reserve(n_vertices);
    }
    void dfs1(int v) {
        used[v] = true;
        for (int u : adj[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : adj_t[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }

    bool solve_2SAT() {
        order.clear();
        used.assign(n_vertices, false);
        for (int i = 0; i < n_vertices; ++i) {
            if (!used[i])
                dfs1(i);
        }

        comp.assign(n_vertices, -1);
        for (int i = 0, j = 0; i < n_vertices; ++i) {
            int v = order[n_vertices - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        assignment.assign(n_vars, false);
        for (int i = 0; i < n_vertices; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }

    void add_disjunction(int a, bool na, int b, bool nb) {
        // na and nb signify whether a and b are to be negated 
        a = 2 * a ^ na;
        b = 2 * b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }
};

class FenwickTree
{
private:
    int64_t* B1;
    int64_t* B2;
    int size;

    void AddOnSingleElement(int index, int64_t* B, int64_t valueToAdd)
    {
        while (index < size)
        {
            B[index] += valueToAdd;

            index = (index | (index + 1));
        }
    }

    int64_t MakeQueryOnPrefix(int lastElementIndex, int64_t* B)
    {
        int64_t ans = 0;

        while (lastElementIndex > 0)
        {
            ans += B[lastElementIndex];

            lastElementIndex &= (lastElementIndex + 1);
            lastElementIndex -= 1;
        }

        return ans;
    }

public:
    FenwickTree(int numberOfElements)
    {
        B1 = new int64_t[numberOfElements + 1]{ 0 };
        B2 = new int64_t[numberOfElements + 1]{ 0 };

        size = numberOfElements + 1;
    }

    ~FenwickTree()
    {
        delete B1;
        delete B2;
    }

    int64_t MakeQueryOnPrefix(int lastElementIndex)
    {
        return MakeQueryOnPrefix(lastElementIndex, B1) * lastElementIndex - MakeQueryOnPrefix(lastElementIndex, B2);
    }

    int64_t MakeQueryOnSegment(int left, int right)
    {
        return MakeQueryOnPrefix(right) - MakeQueryOnPrefix(left);
    }

    void AddOnSegment(int left, int right, int64_t valueToAdd)
    {
        left += 1;

        AddOnSingleElement(left, B1, valueToAdd);
        AddOnSingleElement(right + 1, B1, -valueToAdd);
        AddOnSingleElement(left, B2, valueToAdd * (left - 1));
        AddOnSingleElement(right + 1, B2, -valueToAdd * (right));
    }
};

namespace algos {
    namespace SegmentTreeLazyTraits {
        inline int getBase() { return 0; }
        /*******************************************************************************
         *  Use Traits<Value,Extra> for definition of:
         *      1)  neutral element for `Value`;
         *      2)  neutral element for `Extra`;
         *      3)  how should combine `Extra` with `Value`;
         *      4)  how should combine `Value` with `Value` (children to root);
         *      5)  how should combine `Extra` with `Extra`;
         *  See examples below: TraitsMinAdd<Value, Extra>
         ******************************************************************************/

         /*******************************************************************************
          *  Available traits, implemented in header file SegmentTreeLazyTraits.hpp
          ******************************************************************************/
        template<typename Value, typename Extra> struct LazyMinAdd;
        template<typename Value, typename Extra> struct LazyMaxAdd;
        template<typename Value, typename Extra> struct LazySumSet;
        template<typename Value, typename Extra> struct LazySumMul;
        template<typename Value, typename Extra> struct LazyGeomSumMul;

        /*******************************************************************************
         *  Traits for minimal value on segment.
         *  Get-query:    get minimal value in segment [l, r]
         *  Update-query: add const to each value in segment [l, r]
         ******************************************************************************/
        template<typename Value, typename Extra>
        struct LazyMinAdd {
            // Definition of neutral element for `Value`:
            static Value valueNeutral() { return std::numeric_limits<Value>::max(); }
            // Definition of neutral element for `Extra`:
            static Extra extraNeutral() { return Extra(0); }
            // Definition of how should combine `Extra` with `Value`:
            template<typename Node>
            static Value getValue(const Node& src) {
                return src.value() + src.extra();
            }
            // Definition of how should combine `Value` with `Value` (children to root):
            template<typename NodeRoot, typename NodeLt, typename NodeRt>
            static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
                root.value() = std::min(getValue(lt), getValue(rt));
            }
            // Definition of how should combine `Extra` with `Extra`:
            template<typename NodeDst, typename NodeSrc>
            static void push(NodeDst dst, const NodeSrc& src) {
                dst.extra() += src.extra();
            }
        };

        /*******************************************************************************
         *  Traits for maximal value on segment.
         *  Get-query:    get maximal value in segment [l, r]
         *  Update-query: add const to each value in segment [l, r]
         ******************************************************************************/
        template<typename Value, typename Extra>
        struct LazyMaxAdd {
            // Definition of neutral element for `Value`:
            static Value valueNeutral() { return std::numeric_limits<Value>::min(); }
            // Definition of neutral element for `Extra`:
            static Extra extraNeutral() { return Extra(0); }
            // Definition of how should combine `Extra` with `Value`:
            template<typename Node>
            static Value getValue(const Node& src) {
                return src.value() + src.extra();
            }
            // Definition of how should combine `Value` with `Value` (children to root):
            template<typename NodeRoot, typename NodeLt, typename NodeRt>
            static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
                root.value() = std::max(getValue(lt), getValue(rt));
            }
            // Definition of how should combine `Extra` with `Extra`:
            template<typename NodeDst, typename NodeSrc>
            static void push(NodeDst dst, const NodeSrc& src) {
                dst.extra() += src.extra();
            }
        };

        /*******************************************************************************
         *  Traits for sum of values on segment.
         *  Get-query:    sum of values on segment [l, r]
         *  Update-query: set const to each value in segment [l, r]
         ******************************************************************************/
        template<typename Value, typename Extra>
        struct LazySumSet {
            // Definition of neutral element for `Value`:
            static Value valueNeutral() { return Value(0); }
            // Definition of neutral element for `Extra`:
            static Extra extraNeutral() { return std::numeric_limits<Extra>::min(); }
            // Definition of how should combine `Extra` with `Value`:
            template<typename Node>
            static Value getValue(const Node& src) {
                return src.extra() == extraNeutral() ? src.value() : src.len() * src.extra();
            }
            // Definition of how should combine `Value` with `Value` (children to root):
            template<typename NodeRoot, typename NodeLt, typename NodeRt>
            static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
                root.value() = getValue(lt) + getValue(rt);
            }
            // Definition of how should combine `Extra` with `Extra`:
            template<typename NodeDst, typename NodeSrc>
            static void push(NodeDst dst, const NodeSrc& src) {
                dst.extra() = src.extra();
            }
        };

        /*******************************************************************************
         *  Traits for sum on segment with addition.
         *  Get-query:    sum of values on segment [l, r]
         *  Update-query: add const to each value on segment [l, r]
         ******************************************************************************/
        template<typename Value, typename Extra>
        struct LazySumAdd {
            // Definition of neutral element for `Value`:
            static Value valueNeutral() { return Value(0); }
            // Definition of neutral element for `Extra`:
            static Extra extraNeutral() { return Extra(0); }
            // Definition of how should combine `Extra` with `Value`:
            template<typename Node>
            static Value getValue(const Node& src) {
                return src.value() + src.extra() * src.len();
            }
            // Definition of how should combine `Value` with `Value` (children to root):
            template<typename NodeRoot, typename NodeLt, typename NodeRt>
            static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
                root.value() = getValue(lt) + getValue(rt);
            }
            // Definition of how should combine `Extra` with `Extra`:
            template<typename NodeDst, typename NodeSrc>
            static void push(NodeDst dst, const NodeSrc& src) {
                dst.extra() += src.extra();
            }
        };

        template<typename Value, typename Extra>
        struct LazySumMul {
            // Definition of neutral element for `Value`:
            static Value valueNeutral() { return Value(0); }
            // Definition of neutral element for `Extra`:
            static Extra extraNeutral() { return Extra(1); }
            // Definition of how should combine `Extra` with `Value`:
            template<typename Node>
            static Value getValue(const Node& src) {
                return src.value() * src.extra();
            }
            // Definition of how should combine `Value` with `Value` (children to root):
            template<typename NodeRoot, typename NodeLt, typename NodeRt>
            static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
                root.value() = getValue(lt) + getValue(rt);
            }
            // Definition of how should combine `Extra` with `Extra`:
            template<typename NodeDst, typename NodeSrc>
            static void push(NodeDst dst, const NodeSrc& src) {
                dst.extra() *= src.extra();
            }
        };

        template<typename Value, typename Extra>
        struct LazyGeomSumMul {
            // Definition of neutral element for `Value`:
            static Value valueNeutral() {
                // 1 + b + b^2 + ... + b^len-1
                return Value(0);
            }
            // Definition of neutral element for `Extra`:
            static Extra extraNeutral() { return Extra(1); }
            // Definition of how should combine `Extra` with `Value`:
            template<typename Node>
            static Value getValue(const Node& src) {
                auto result = (src.value() == valueNeutral()
                    ? geometricSum(getBase(), src.len()) * binpow(getBase(), src.left())
                    : src.value()) * src.extra();
                return result;
            }
            // Definition of how should combine `Value` with `Value` (children to root):
            template<typename NodeRoot, typename NodeLt, typename NodeRt>
            static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
                root.value() = getValue(lt) + getValue(rt);
            }
            // Definition of how should combine `Extra` with `Extra`:
            template<typename NodeDst, typename NodeSrc>
            static void push(NodeDst dst, const NodeSrc& src) {
                dst.extra() *= src.extra();
            }
        };

    } // namespace SegmentTreeLazyTraits
} // namespace algos

namespace algos {
    namespace SegmentTreeLazy {
        using namespace algos::SegmentTreeLazyTraits;
        /*******************************************************************************
         *  SegmentTree<Value, Extra, Traits> - segment tree class with lazy propagation, 0-indexed
         *  Default operations: minimal value on segment and addition on segment for int64_t type
         *  Use Traits<Value,Extra> for definition of:
         *      1)  neutral element for `Value`;
         *      2)  neutral element for `Extra`;
         *      3)  how should combine `Extra` with `Value`;
         *      4)  how should combine `Value` with `Value` (children to root);
         *      5)  how should combine `Extra` with `Extra`;
         *  See examples below: TraitsMinAdd<Value, Extra>
         ******************************************************************************/

         /*******************************************************************************
          *  Available traits, implemented below
          ******************************************************************************/
        template<typename Value, typename Extra> using TraitsMinAdd = LazyMinAdd<Value, Extra>;
        template<typename Value, typename Extra> using TraitsMaxAdd = LazyMaxAdd<Value, Extra>;
        template<typename Value, typename Extra> using TraitsSumSet = LazySumSet<Value, Extra>;
        template<typename Value, typename Extra> using TraitsSumMul = LazySumMul<Value, Extra>;

        /*******************************************************************************
         *  SegmentTree, see description above
         ******************************************************************************/
        template<typename Value = int64_t, typename Extra = int64_t, typename Traits = TraitsMinAdd<Value, Extra> >
        struct SegmentTree {

            /*******************************************************************************
             *  Node class
             ******************************************************************************/
            struct Node {
                Value value;

                Extra extra;

                Node(Value value_ = Traits::valueNeutral(), Extra extra_ = Traits::extraNeutral())
                    : value(value_), extra(extra_) {
                }

                Value getValue(int l, int r) const { return Traits::getValue(NodeWrapper<Node>(l, r, *this)); }
            };

            /*******************************************************************************
             *  NodeWrapper class
             ******************************************************************************/
            template<typename NodeType>
            struct NodeWrapper {
                int l, r;
                NodeType node;
                NodeWrapper(int l_, int r_, NodeType node_)
                    : l(l_), r(r_), node(node_) {
                }
                int  left() const { return l; }
                int right() const { return r; }
                int   mid() const { return (l + r) / 2; }
                int   len() const { return r - l + 1; }
                Value& value() { return node.value; }
                Extra& extra() { return node.extra; }
                const Value& value() const { return node.value; }
                const Extra& extra() const { return node.extra; }
            };

            /*******************************************************************************
             *  SegmentTree public data: n - number of items, data - vector for nodes
             ******************************************************************************/
            int n; std::vector<Node> data;


            /*******************************************************************************
             *  Resize segment tree data to needed size
             ******************************************************************************/
            void resize(int n_) {
                n = n_;
                data.assign(2 * n - 1, Node());
            }

            /*******************************************************************************
             *  Lazy propagation from node to its children
             ******************************************************************************/
            void push(int v, int l, int r, int m) {
                if (data[v].extra != Traits::extraNeutral()) {
                    Traits::push(
                        NodeWrapper<Node&>(l, m, data[v + 1]),
                        NodeWrapper<const Node&>(l, r, data[v])
                    );
                    Traits::push(
                        NodeWrapper<Node&>(m + 1, r, data[v + 2 * (m - l + 1)]),
                        NodeWrapper<const Node&>(l, r, data[v])
                    );
                    data[v].extra = Traits::extraNeutral();
                }
            }

            /*******************************************************************************
             *  Update node using children values
             ******************************************************************************/
            void pull(int v, int l, int r, int m) {
                assert(data[v].extra == Traits::extraNeutral());
                Traits::pull(
                    NodeWrapper<Node&>(l, r, data[v]),
                    NodeWrapper<const Node&>(l, m, data[v + 1]),
                    NodeWrapper<const Node&>(m + 1, r, data[v + 2 * (m - l + 1)])
                );
            }

            /*******************************************************************************
             *  Build segtree from array with given values
             ******************************************************************************/
            template<typename T>
            void build(const std::vector<T>& arr, const int v, const int tl, const int tr) {
                if (tl == tr) {
                    data[v] = Node(arr[tl]);
                }
                else {
                    const int tm = (tl + tr) / 2;
                    build(arr, v + 1, tl, tm);
                    build(arr, v + 2 * (tm - tl + 1), tm + 1, tr);
                    pull(v, tl, tr, tm);
                }
            }

            template<typename T>
            void build(const std::vector<T>& arr) {
                resize((int)arr.size());
                build(arr, 0, 0, n - 1);
            }

            /*******************************************************************************
             *  Get-query on range [ql, qr]
             ******************************************************************************/
            Node get(int ql, int qr, const int v, const int tl, const int tr) {
                if (ql == tl && qr == tr) {
                    return data[v];
                }
                else {
                    int tm = (tl + tr) / 2;
                    push(v, tl, tr, tm);
                    Node ret;
                    if (qr <= tm) {
                        ret = get(ql, qr, v + 1, tl, tm);
                    }
                    else if (ql > tm) {
                        ret = get(ql, qr, v + 2 * (tm - tl + 1), tm + 1, tr);
                    }
                    else {
                        const auto lt = get(ql, tm, v + 1, tl, tm);
                        const auto rt = get(tm + 1, qr, v + 2 * (tm - tl + 1), tm + 1, tr);
                        Traits::pull(
                            NodeWrapper<Node&>(ql, qr, ret),
                            NodeWrapper<const Node&>(ql, tm, lt),
                            NodeWrapper<const Node&>(tm + 1, qr, rt)
                        );
                    }
                    pull(v, tl, tr, tm);
                    return ret;
                }
            }

            Value get(const int ql, const int qr) { return get(ql, qr, 0, 0, n - 1).getValue(ql, qr); }

            /*******************************************************************************
             *  Update query on range [ql, qr] by extra
             ******************************************************************************/
            void update(const int ql, const int qr, const Extra& extra, const int v, const int tl, const int tr) {
                if (ql == tl && tr == qr) {
                    Traits::push(
                        NodeWrapper<Node&>(tl, tr, data[v]),
                        NodeWrapper<Node>(ql, qr, Node(Traits::valueNeutral(), extra))
                    );
                }
                else {
                    int tm = (tl + tr) / 2;
                    push(v, tl, tr, tm);
                    if (qr <= tm) {
                        update(ql, qr, extra, v + 1, tl, tm);
                    }
                    else if (ql > tm) {
                        update(ql, qr, extra, v + 2 * (tm - tl + 1), tm + 1, tr);
                    }
                    else {
                        update(ql, tm, extra, v + 1, tl, tm);
                        update(tm + 1, qr, extra, v + 2 * (tm - tl + 1), tm + 1, tr);
                    }
                    pull(v, tl, tr, tm);
                }
            }

            void update(const int ql, const int qr, const Extra& extra) {
                update(ql, qr, extra, 0, 0, n - 1);
            }

        };

    } // namespace SegmentTreeLazy
} // namespace algos

vector<long> prefix_function(string s)
{
    long n = s.size();

    vector<long> p(n + 11);

    p[0] = 0;

    for (int i = 2; i <= n; i++)
    {
        long len = p[i - 1];

        while (s[i - 1] != s[len] && len != 0)
        {
            len = p[len];
        }

        if (len == 0)
        {
            if (s[0] == s[i - 1])
            {
                p[i] = 1;
            }
            else p[i] = 0;
        }
        else
        {
            p[i] = len + 1;
        }
    }

    return p;
}

long getSum(long nm)
{
    long ans = 0;

    while (nm > 0)
    {
        ans += nm % 10;
        nm /= 10;
    }

    return ans;
}

long powLong(long nm, long p)
{
    long ans = 1;

    for (int i = 0; i < p; i++)
    {
        ans *= nm;
    }

    return ans;
}

void solve()
{
    map<string, string> table;

    table["GGGgGGG"] = "0";
    table["gggggGG"] = "1";
    table["gGGGGGg"] = "2";
    table["ggGGGGG"] = "3";
    table["GggGgGG"] = "4";
    table["GgGGGgG"] = "5";
    table["GGGGGgG"] = "6";
    table["ggGggGG"] = "7";
    table["GGGGGGG"] = "8";
    table["GgGGGGG"] = "9";

    long n;
    cin >> n;

    string ans;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        set<string> vars;

        for (int mask = 0; mask < (1ll << 7); mask++)
        {
            string var;

            for (int bit = 0; bit < 7; bit++)
            {
                if (s[bit] == '+' || s[bit] == '-')
                {
                    if ((1ll << bit) & mask)
                    {
                        var.push_back('G');
                    }
                    else var.push_back('g');
                }
                else var.push_back(s[bit]);
            }

            if (table.count(var))
                vars.insert(var);

            if (vars.size() >= 2)
                break;
        }

        if (vars.size() >= 2)
        {
            ans += "*";
        }
        else
        {
            ans += table[*vars.begin()];
        }
    }

    cout << ans;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);

    long t = 1;
    //cin >> t;

    for (int t1 = 0; t1 < t; t1++)
    {
        solve();
    }
}