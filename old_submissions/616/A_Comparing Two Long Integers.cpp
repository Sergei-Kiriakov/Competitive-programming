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

string sh (string s)
{
    int n = s.size();
    string s1;
    int i = 0;
    while (i < n && s[i] == '0')
    {
        ++i;
    }
    if (i == n)
    {
        return "0";
    }
    for (int j = i; j < n; ++j)
    {
        s1.push_back(s[j]);
    }
    return s1;
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    s1 = sh(s1);
    s2 = sh(s2);
    int n1 = s1.size(), n2 = s2.size();
    if (n1 > n2)
    {
        cout << ">" << "\n";
    }
    else if (n2 > n1)
    {
        cout << "<" << "\n";
    }
    else
    {
        int i = 0;
        while (i < n1 && s1[i] == s2[i])
        {
            ++i;
        }
        if (i == n1)
        {
            cout << "=" << "\n";
        }
        else if (s1[i] > s2[i])
        {
            cout << ">" << "\n";
        }
        else
        {
            cout << "<" << "\n";
        }
    }
}

/*
*/
