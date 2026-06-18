#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("avx2,bmi2")
#include <iostream>
#include <vector>
#include <map>
#include <assert.h>
#include <algorithm>
#include <string>
#include <set>
#include <time.h>
#include <cmath>
#include <iomanip>
using namespace std;
using ld = long double;
using ll = long long;
using ull = unsigned long long;
const ll mod = 1e9+7;
const ll mll = 1e18;

ll sum_digit(ll x){
    ll ans = 0;
    while (x>0){
        ans+=x%10;
        x/=10;
    }
    return ans;
}
ll cnt_s(ll a, ll b){
    if (a>b) return 0;
    return (a+b)*(b-a+1)/2;
}
void solve(){
    ll t, n, m;
    cin >> t >> n >> m;
    bool f = 1;
    ll mx = 0;
    ll mn = 0;
    ll curr_t = 0;
    ll curr_sec = 0;
    ll x, y;
    cin >> x >> y;
    mx+=cnt_s(y, y+x-1);
    mn+=cnt_s(y-(x-1), y);
    if (y-(x-1)) {
        mn-=cnt_s(y-(x-1), 0);
    }
    curr_t = y;
    curr_sec = x;
    for (int i=1; i<m; i++){
        ll a, b;
        cin >> a >> b;
        if (a-curr_sec<abs(b-curr_t)){
            f = 0;
            break;
        }
        if (b>=curr_t){
            ll free_sec = (a-curr_sec-(b-curr_t));
            mx+=cnt_s(curr_t+1, b)+(b+b+free_sec/2)*(free_sec/2)+(free_sec%2)*(b+free_sec/2);
            mn+=cnt_s(curr_t+1, b)+(curr_t+curr_t-free_sec/2)*(free_sec/2)+(free_sec%2)*(curr_t-free_sec/2);
            if (curr_t-free_sec/2<0){
                mn+=(curr_t-free_sec/2)*(curr_t-free_sec/2)-(free_sec%2)*(curr_t-free_sec/2);
            }
        }else{
            ll free_sec = (a-curr_sec-(curr_t-b));
            mx+=cnt_s(b, curr_t-1)+(curr_t+curr_t+free_sec/2)*(free_sec/2)+(free_sec%2)*(curr_t+free_sec/2);
            mn+=cnt_s(b, curr_t-1)+(b+b-free_sec/2)*(free_sec/2)+(free_sec%2)*(b-free_sec/2);
            if (b-free_sec/2<0){
                mn+=(b-free_sec/2)*(b-free_sec/2)-(free_sec%2)*(b-free_sec/2);
            }
        }
        curr_sec = a;
        curr_t = b;
    }
    mx+=cnt_s(curr_t+1, n-curr_sec+curr_t);
    mn+=cnt_s(curr_t-(n-curr_sec), curr_t-1);
    if (curr_t-(n-curr_sec)<0){
        mn -=cnt_s(curr_t-(n-curr_sec), 0);
    }
    //cout << mn << " " << mx << '\n';
    if (mn<=t && mx>=t && f) cout << "Yes\n";
    else cout << "No\n";
}
int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 //precalc_primes();
 int t=1;
 //cin >> t;
 while (t--){
  solve();
 }
}

