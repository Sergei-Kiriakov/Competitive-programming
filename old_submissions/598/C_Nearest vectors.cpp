#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<vvi> vvvi;
typedef std::vector<vvvi> vvvvi;
typedef std::vector<std::string> vs;
typedef std::vector<bool> vb;
typedef std::vector<vb> vvb;
typedef std::vector<double> vd;
typedef std::vector<vd> vvd;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
typedef std::vector<vpii> vvpii;
using ull = unsigned long long;

using namespace std;

const int mod = 1e9 + 7, MAXN = 400 + 4;

int cross_prod(pii a, pii b)
{
    return a.first * b.second - a.second * b.first;
}

int dot_prod(pii a, pii b)
{
    return a.first * b.first + a.second * b.second;
}

bool top(pii a)
{
    return a.second > 0 || (a.second == 0 && a.first > 0);
}

bool comp(pii a, pii b)
{
    bool ta = top(a), tb = top(b);
    if (ta != tb)
        return ta;
    return cross_prod(a, b) > 0;
}

bool les (pii a1, pii b1, pii a2, pii b2)
{
    pii p1 = {dot_prod(a1, b1), abs(cross_prod(a1, b1))};
    pii p2 = {dot_prod(a2, b2), abs(cross_prod(a2, b2))};
    return cross_prod(p1, p2) > 0;
}

int len (pii a)
{
    return a.first * a.first + a.second * a.second;
}

int cross_prod2(pii a, pii b)
{
    return cross_prod(a, b) * cross_prod(a, b);
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n;
    cin >> n;
    vpii a(n);
    map<pii, int> c;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        c[a[i]] = i;
    }
    sort(a.begin(), a.end(), comp);
    int ans1 = 0, ans2 = 1;
    for (int i = 0; i < n; ++i)
    {
        int j = (i + 1) % n;
        if (les(a[i], a[j], a[ans1], a[ans2]))
        {
            ans1 = i;
            ans2 = j;
        }
    }
    cout << c[a[ans1]] + 1 << " " << c[a[ans2]] + 1 << "\n";
}

/*
*/
