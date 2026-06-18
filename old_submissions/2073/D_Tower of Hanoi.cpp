#include <functional>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
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
    vector<vector<int>> adj;

    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;

    void dfs(int v, int p)
    {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i - 1]][i - 1];

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }

        tout[v] = ++timer;
    }

    void preprocess(int root) {
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1));
        dfs(root, root);
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
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }

    LCA(long N, long root, vector<vector<int>>& g)
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

struct blockAns 
{
    long sum;
    long first_need_pos;
    long last_pos;
};

void solve()
{
    const long MOD = 998244353;

    long n, q;
    cin >> n >> q;

    vector<long> pos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> pos[i];
    }

    vector<long> step2(n + 1);

    step2[0] = 1;

    for (int i = 1; i <= n; i++)
        step2[i] = (step2[i - 1] * 2ll) % MOD;

    long k = sqrt(n);

    vector<vector<blockAns>> blocks(n / k + 1, vector<blockAns>(4));

    auto calc_ans = [&](long l, long r, long need_pos, const vector<long>& a, auto&& calc_ans) -> blockAns
    {
        blockAns ans = {0, need_pos, -1};
        for (int i = r; i >= l; --i) {
            if (a[i] != need_pos) {
                blockAns ansNext = calc_ans(l, i - 1, 6 - a[i] - need_pos, a, calc_ans);

                ans.sum = (ans.sum + ansNext.sum) % MOD;
                ans.sum = (ans.sum + step2[i - l]) % MOD;

                ans.last_pos = i;
                ans.first_need_pos = ansNext.first_need_pos;

                return ans;
            }
        }
        return ans;
    };

    for (int i = 0; i < n / k + 1; i++)
    {
        long left = i * k, right = min((i + 1) * k - 1, n - 1);

        for (int j = 1; j <= 3; j++)
        {
            blocks[i][j] = calc_ans(left, right, j, pos, calc_ans);
        }
    }
    
    auto getOnSeg = [&](long l, long r) -> long
    {
        long left = l / k;
        long right = r / k;

        blockAns ans;

        if (left == right)
        {
            ans = calc_ans(l, r, 1, pos, calc_ans);
        }
        else
        {
            for (int indBlock = right; indBlock >= left; indBlock--)
            {
                if (indBlock == right)
                {
                    ans = calc_ans(right * k, r, 1, pos, calc_ans);
                }
                else if (indBlock == left)
                {
                    blockAns newAns = calc_ans(l, (left + 1) * k - 1, ans.first_need_pos, pos, calc_ans);

                    long lenAdd = (left + 1) * k - 1 - l + 1;

                    ans.sum = (ans.sum * step2[lenAdd]) % MOD;
                    ans.sum = (ans.sum + newAns.sum) % MOD;
                    ans.first_need_pos = newAns.first_need_pos;
                }
                else
                {
                    blockAns newAns = blocks[indBlock][ans.first_need_pos];

                    long lenAdd = k;

                    ans.sum = (ans.sum * step2[lenAdd]) % MOD;
                    ans.sum = (ans.sum + newAns.sum) % MOD;
                    ans.first_need_pos = newAns.first_need_pos;
                }
            }
        }

        return ans.sum;
    };
    
    auto chPos = [&](long changeTo, long posC) -> void
    {
        long blockInd = posC / k;
        pos[posC] = changeTo;

        long left = blockInd * k, right = min((blockInd + 1) * k - 1, n - 1);

        for (int j = 1; j <= 3; j++)
        {
            blocks[blockInd][j] = calc_ans(left, right, j, pos, calc_ans);
        }
    };

    for (int q1 = 1; q1 <= q; q1++)
    {
        string t;
        long a, b;

        cin >> t >> a >> b;

        if(t == "s")
        {
            a--;
            b--;

            cout << getOnSeg(a, b) << '\n';
        }
        else
        {
            a--;

            chPos(b, a);
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
