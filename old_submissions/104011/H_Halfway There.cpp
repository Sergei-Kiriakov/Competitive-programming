#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()


using namespace std;

const int mod = 1e9 + 7, kk = 26;

int ans = 0;

struct Vertex {
    Vertex* to[kk] = {0};
    bool terminal = 0;
    int cnt = 0;
};

Vertex *root = new Vertex();

void add_string(string &s) {
    Vertex* v = root;
    ++v->cnt;
    for (char c : s) {
        c -= 'a';
        if (!v->to[c])
        {
          v->to[c] = new Vertex();
        }
        v = v->to[c];
        ++v->cnt;
    }
    v->terminal = true;
}

void get_ans(Vertex* v, int k)
{
  if (v->cnt <= k)
  {
    ++ans;
    return;
  }
  for (int i = 0; i < kk; ++i)
    {
      Vertex* w = v->to[i];
      if (w->cnt != 0)
      {
        get_ans(w, k);
      }
    }
}

void solve()
{
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    {
      string s;
      cin >> s;
      add_string(s);
    }
  get_ans(root, k);
  cout << ans << endl;
}

void solveH(){
  int t;
  cin >> t;
  while (t-->0){
    int n;
    cin >> n;
    for (int i = n / 2; i > 0; --i){
      if (__gcd(i, n) == 1){
        cout << i << '\n';
        break;
      }
    }
  }
}

int32_t main()
{
    //ofstream cout("sum.out");
    //ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    //cin >> tt;
    while(tt-->0)
    {
        solveH();
    }
}


/*
*/