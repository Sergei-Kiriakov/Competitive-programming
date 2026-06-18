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

namespace SegmentTree {
    /**
     * Traits for min on segment and set single element queries (by default)
     */
    template<typename T>
    struct TraitsMinSet {
        static T neutral() { return std::numeric_limits<T>::max(); }
        static void update(T& dst, T src) { dst = src; }
        static void merge(T& dst, const T& lhs, const T& rhs) { dst = std::min(lhs, rhs); }
    };

    /**
     *  List of additional traits, implemented below
     */
    template<typename T> struct TraitsMaxSet; // max on segment, set single element
    template<typename T> struct TraitsSumSet; // sum on segment, set single element
    template<typename T> struct TraitsGCDSet; // gcd on segment, set single element
    template<typename T> struct TraitsMinAdd; // min on segment, add to single element
    template<typename T> struct TraitsMaxAdd; // max on segment, add to single element
    template<typename T> struct TraitsSumAdd; // sum on segment, add to single element
    template<typename T> struct TraitsGCDAdd; // gcd on segment, add to single element

    /**
     * SegmentTree class. Effective bottom-to-top implementation
     */
    template<typename ItemType = int64_t, typename ItemTraits = TraitsMinSet<ItemType>>
    struct SegmentTree {
        /**
         * Public data: `n` - number of items in array and `data` - tree's container
         */
        int n; std::vector<ItemType> data;

        /**
         * Main methods: resize(nItems), build(array), get(left, right), where 0 <= left <= right < nItems
         */
        void resize(const int n_) {
            n = n_;
            int pow = 1;
            while (pow < n) { pow *= 2; }
            data.assign(2 * pow, ItemTraits::neutral());
        }

        template<typename T>
        void build(const std::vector<T>& arr) {
            resize((int)arr.size());
            for (int v = 0; v < n; ++v) {
                data[v + n] = arr[v];
            }
            for (int v = n - 1; v >= 1; --v) {
                ItemTraits::merge(data[v], data[2 * v], data[2 * v + 1]);
            }
        }

        ItemType get(int ql, int qr) const {
            ItemType ret = ItemTraits::neutral();
            for (ql += n, qr += n; ql <= qr; ql /= 2, qr /= 2) {
                if (ql % 2 == 1) { ItemTraits::merge(ret, ret, data[ql++]); }
                if (qr % 2 == 0) { ItemTraits::merge(ret, ret, data[qr--]); }
            }
            return ret;
        }

        void update(int pos, ItemType val) {
            int v = pos + n;
            ItemTraits::update(data[v], val);
            for (v /= 2; v > 0; v /= 2) {
                ItemTraits::merge(data[v], data[2 * v], data[2 * v + 1]);
            }
        }
    }; /** SegmentTree class end */

    /**
     * Traits for max on segment and set single element queries
     */
    template<typename T>
    struct TraitsMaxSet {
        static T neutral() { return std::numeric_limits<T>::min(); }
        static void update(T& dst, T src) { dst = src; }
        static void merge(T& dst, const T& lhs, const T& rhs) { dst = std::max(lhs, rhs); }
    };

    /**
     * Traits for sum on segment and set single element queries
     */
    template<typename T>
    struct TraitsSumSet {
        static T neutral() { return T(0); }
        static void update(T& dst, T src) { dst = src; }
        static void merge(T& dst, const T& lhs, const T& rhs) { dst = lhs + rhs; }
    };

    /**
     * Traits for min on segment and add to single element queries
     */
    template<typename T>
    struct TraitsMinAdd {
        static T neutral() { return std::numeric_limits<T>::max(); }
        static void update(T& dst, T src) { dst += src; }
        static void merge(T& dst, const T& lhs, const T& rhs) { dst = std::min(lhs, rhs); }
    };

    /**
     * Traits for max on segment and add to single element queries
     */
    template<typename T>
    struct TraitsMaxAdd {
        static T neutral() { return std::numeric_limits<T>::min(); }
        static void update(T& dst, T src) { dst += src; }
        static void merge(T& dst, const T& lhs, const T& rhs) { dst = std::max(lhs, rhs); }
    };

    /**
     * Traits for sum on segment and add to single element queries
     */
    template<typename T>
    struct TraitsSumAdd {
        static T neutral() { return T(0); }
        static void update(T& dst, T src) { dst += src; }
        static void merge(T& dst, const T& lhs, const T& rhs) { dst = lhs + rhs; }
    };

} /** SegmentTree namespace end */

template<typename T>
struct MinPos {
    T val; int pos;
    MinPos(T val_ = std::numeric_limits<T>::max(), int pos_ = 0)
        : val(val_), pos(pos_) {
    }
};

template<typename T>
struct TraitsMinPos {
    static T neutral() { return T(); }
    static void update(T& dst, T src) { dst = src; }
    static void merge(T& dst, const T& lhs, const T& rhs) {
        dst = (lhs.val < rhs.val || (lhs.val == rhs.val && lhs.pos < rhs.pos)) ? lhs : rhs;
    }
};

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

void solve()
{
    long n, m;
    cin >> n >> m;

    vector<vector<long>> g(n + 1, vector<long>(n + 1, 1e9));

    vector<long> a(m + 1), b(m + 1);

    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i];

        g[a[i]][b[i]] = -1;
    }

    vector<vector<long>> ans;

    while (ans.size() <= 50000)
    {
        vector<pair<long, pair<long, long>>> need;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j)
                {
                    need.push_back({ g[i][j], {i, j} });
                }
            }
        }

        sort(need.begin(), need.end());

        if (need[0].first >= 0)
        {
            break;
        }

        vector<vector<long>> gCur(n + 1);

        vector<char> cl(n + 1);
        vector<int> p(n + 1, -1);

        auto dfs = [&](int v, auto&& dfs) -> bool
            {
                cl[v] = 1;
                for (size_t i = 0; i < gCur[v].size(); ++i) {
                    int to = gCur[v][i];
                    if (cl[to] == 0) {
                        p[to] = v;
                        if (dfs(to, dfs))  return true;
                    }
                    else if (cl[to] == 1) {
                        return true;
                    }
                }
                cl[v] = 2;
                return false;
            };

        vector<long> perm(n + 1);

        for (int i = 0; i < need.size(); i++)
        {
            p.assign(n + 1, -1);
            cl.assign(n + 1, 0);

            gCur[need[i].second.first].push_back(need[i].second.second);

            bool pop = false;

            for (int j = 1; j <= n; j++)
            {
                if (dfs(j, dfs))
                {
                    pop = true;
                    break;
                }
            }

            if (pop)
                gCur[need[i].second.first].pop_back();
        }

        vector<long> ord;
        vector<bool> was(n + 1);

        auto dfsConstr = [&](long curV, auto&& dfsConstr) -> void
            {
                if (was[curV])
                    return;

                was[curV] = true;

                for (auto& next : gCur[curV])
                {
                    dfsConstr(next, dfsConstr);
                }

                ord.push_back(curV);
            };

        for (int i = 1; i <= n; i++)
            dfsConstr(i, dfsConstr);


        for (int i = n; i >= 1; i--)
        {
            perm[i] = ord[n - i];
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                g[perm[i]][perm[j]]++;
                g[perm[j]][perm[i]]--;
            }
        }

        ans.push_back(perm);
    }

    if (ans.size() > 50000)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n";
        cout << ans.size() << '\n';

        for (auto& el : ans)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << el[i] << ' ';
            }

            cout << '\n';
        }
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);

    long t;
    t = 1;

    for (int t1 = 0; t1 < t; t1++)
    {
        solve();
    }
}