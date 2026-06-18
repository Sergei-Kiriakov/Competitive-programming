#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179, MAX = 2 * 1e5;

int n, tree[4 * MAX];

void build (vector<int> &a, int v, int tl, int tr, int turn)
{
    if (tl == tr)
        tree[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm, turn - 1);
        build(a, v * 2 + 1, tm + 1, tr, turn - 1);
        if (turn % 2 == 1)
        {
            tree[v] = tree[v * 2] | tree[v * 2 + 1];
        }
        else
        {
            tree[v] = tree[v * 2] ^ tree[v * 2 + 1];
        }
    }
}

void update (int v, int tl, int tr, int pos, int new_val, int turn) {
    if (tl == tr)
        tree[v] = new_val;
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v * 2, tl, tm, pos, new_val, turn - 1);
        else
            update (v * 2 + 1, tm + 1, tr, pos, new_val, turn - 1);
        if (turn % 2 == 1)
        {
            tree[v] = tree[v * 2] | tree[2 * v + 1];
        }
        else
        {
            tree[v] = tree[v * 2] ^ tree[2 * v + 1];
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int N = (1 << n);
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    build(a, 1, 0, N - 1, n);
    for (int i = 0; i < m; ++i)
    {
        int p, b;
        cin >> p >> b;
        update(1, 0, N - 1, p - 1, b, n);
        cout << tree[1] << endl;
    }
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    solve();
}
