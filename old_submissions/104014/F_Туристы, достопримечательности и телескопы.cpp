#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;
/*
pair<int, int> f(string s)
{
  pair<int, int> ans = {0, 0};
  int n = s.size();
  int i = 0;
  while (i < n && s[i] != ',')
    {
      ans.first *= 10;
      ans.first += s[i] - '0';
    }
  i++;
  while (i < n)
    {
      ans.second *= 10;
      ans.second += s[i] - '0';
    }
  return ans;
}

void solve()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  pair<int, int> mon = f(s);
  vector<pair<int, string> > a;
  for (int i = 0; i < n; ++i)
    {
      string name, s1;
      cin >> name >> s1;
      pair<int, int> mon1 = f(s1);
      a.push_back({mon1.first * 100 + mon1.second, name});
    }
  sort(a.begin(), a.end());
  string ans = "";
  for (int i = 0; i < n; ++i)
    {
      if (a[i][0] / 100 <= mon.first && a[i][0] % 100 <= mon.second)
      {
        ans = a[i][1];
        break;
      }
    }
  if (ans == "")
  {
    cout << -1 << endl;
  }
  else
  {
    cout << ans << endl;
  }
}*/
void solution(){
  long long n, R;
  cin >> n >> R;
  long long a[n];
  for (int i=0; i<n; i++){
    cin >> a[i];
  }
  long long pr[n+1];
  pr[0]=0;
  for (int i=0; i<n; i++){
    pr[i+1]=pr[i]+a[i];
  }
  for (int i=0; i<n; i++){
    int l=0;
    int r = max(i, n-1-i)+1;
    while (r-l>1){
      int m = (l+r)/2;
      long long x = pr[min(n, i+m+1)]-pr[max((int)0, i-m)];
      //cout << m << " " <<  x << " ";
      if (x<=R){
        l = m;
      }else{
        r = m;
      }
    }
    if (a[i]>R) cout << "-1\n";
    else cout << l << '\n';
  }
}
int32_t main()
{
    //ofstream cout("sum.out");
    //ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    solution();
}


/*
*/  