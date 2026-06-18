#include <functional>
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <string>
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
#include <cassert>
#include <unordered_set>

using namespace std;

#define long long long

struct DSU {
    vector<int> par, sz;
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
                    : value(value_), extra(extra_) { }

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
                    : l(l_), r(r_), node(node_) { }
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

using namespace algos::SegmentTreeLazy;
using namespace algos::SegmentTreeLazyTraits;

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

#define MOD 998244353

long binPow(long a, long p, long m)
{
    if (p == 0)
        return 1;

    if (p == 1)
        return a % m;

    if (p % 2 == 0)
    {
        long v = binPow(a, p / 2, m);

        return v * v % m;
    }
    else
    {
        long v = binPow(a, p / 2, m);

        return (v * v % m) * (a % m) % m;
    }
}

long lcm(long a, long b)
{
    return a * b / gcd(a, b);
}

long ex_gcd(long a, long b, long& x, long& y) 
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long x1, y1;
    long d = ex_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve()
{
    long n;
    cin >> n;

    vector<long> a(n);

    map<long, long> cnts;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnts[a[i]]++;
    }

    vector<string> opers;
    
    while (cnts[2] && cnts[1])
    {
        if (cnts[2] == 1 && cnts[1] <= 3)
        {
            if (cnts[1] == 3)
            {
                opers.push_back("(2+1)*(1+1)");
            }
            else if(cnts[1] == 2)
            {
                opers.push_back("(2+1+1)");
            }
            else
            {
                opers.push_back("(2+1)");
            }

            cnts[1] = 1;
        }
        else opers.push_back("(2+1)");

        cnts[2]--;
        cnts[1]--;
    }

    while (cnts[1] > 0)
    {
        if (cnts[1] >= 3)
        {
            if (cnts[1] == 4)
            {
                opers.push_back("(1+1+1+1)");
                cnts[1] -= 4;
            }
            else
            {
                opers.push_back("(1+1+1)");
                cnts[1] -= 3;
            }
        }
        else
        {
            if (cnts[1] == 2)
            {
                opers.push_back("(1+1)");
                cnts[1] -= 2;
            }
            else
            { 
                cnts.erase(1);
                cnts.erase(2);

                auto lb = cnts.lower_bound(0);

                if (lb == cnts.end())
                {
                    opers.push_back("(1)");
                }
                else
                {
                    opers.push_back("(1+" + to_string(lb->first) + ")");
                    cnts[lb->first]--;
                }
            }
        }
    }

    for (auto& c : cnts)
    {
        for (int i = 0; i < c.second; i++)
            opers.push_back(to_string(c.first));
    }

    for (int i = 0; i < opers.size(); i++)
    {
        cout << opers[i];

        if (i != (long)opers.size() - 1)
        {
            cout << "*";
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);

    long t;
    t = 1;

    for (int t1 = 0; t1 < t; t1++)
    {
        solve();
    }
}
