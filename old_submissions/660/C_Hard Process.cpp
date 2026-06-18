#include <bits/stdc++.h>
#define int int64_t
#define double long double

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<vvi> vvvi;
typedef std::vector<std::string> vs;
typedef std::vector<bool> vb;
typedef std::vector<vb> vvb;
typedef std::vector<double> vd;
typedef std::vector<vd> vvd;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
typedef std::vector<vpii> vvpii;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179, MAXN = 1000000;

int randi (int l, int r)
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int k = r - l + 1;
    return rng() % k + l;
}

int gcd (int a, int b)
{
    while (b != 0)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    deque<int> q;
    q.push_back(n);
    int ans = 0;
    int ind = -1;
    for (int i = n - 1; i > -1; --i)
    {
        if (a[i] == 0)
        {
            q.push_front(i);
        }
        while (q.size() > k + 1)
        {
            q.pop_back();
        }
        if (ans < q.back() - i)
        {
            ans = q.back() - i;
            ind = i;
        }
    }
    int cnt = 0;
    for (int i = ind; cnt < k && i < n; ++i)
    {
        if (a[i] == 0)
        {
            a[i] = 1;
            ++cnt;
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

/*
5
1 2 3 4 5
1 3
2 3
*/
