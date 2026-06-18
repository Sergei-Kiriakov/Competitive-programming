#include <cassert>
#include <chrono>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <random>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using v_pll = vector<pll>;

bool IsPrimeSquare(ll x){
    ll d = 2;
    while (d*d <=x && x%d!=0){
        d++;
    }
    if (d*d == x){
        return true;
    }
    return false;
}

void solve(){
    ll n, m;
    cin >>  n  >> m;
    if  (n==1 && m==1){
        cout << "Yes\n";
        cout << "0 \n";
        cout << "0 \n";
        return;
    }
    if (n==1){
      cout << "Yes\n";
      cout  <<  "1\n";
      for (int i = 0; i < m; i++) {
        cout << i << " ";
      }
      cout << '\n';
      return;
    }
    if (m == 1) {
      cout << "Yes\n";
      for (int i = 0; i < n; i++) {
        cout << i << " ";
      }
      cout << '\n';
      cout << "1\n";
      return;
    }
    if (gcd(m, n)!=1){
        cout << "No\n";
        return;
    }
    cout <<  "Yes\n";
    for (int i=0; i<n; i++){
        cout << m*i+1 << " ";
    }
    cout << '\n';
    for (int j=0; j<m; j++){
        cout << 1+j*n << " ";
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t =1;
    cin >> t;
    while(t--){
        solve();
    }
}
