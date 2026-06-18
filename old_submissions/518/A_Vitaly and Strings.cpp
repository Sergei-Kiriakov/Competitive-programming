#include <bits/stdc++.h>
#define int long long

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

constexpr int mod = 1e9 + 7, p = 179;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    string s3;
    bool flag = false;
    int i = n - 1;
    while (s1[i] == 'z')
    {
        --i;
    }
    s1[i] += 1;
    ++i;
    while (i < n)
    {
        s1[i] = 'a';
        ++i;
    }
    if (s1 == s2)
    {
        cout << "No such string" << endl;
    }
    else
    {
        cout << s1 << endl;
    }
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
