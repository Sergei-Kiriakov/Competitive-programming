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

ll pow(ll a, ll p = mod - 2){
    if (p==0) return 1;
    else if (p&1) return a*pow(a, p-1)%mod;
    else {
        ll res = pow(a, p/2);
        return res*res%mod;
    }
}
ll sum_digit(ll x){
    ll ans = 0;
    while (x>0){
        ans+=x%10;
        x/=10;
    }
    return ans;
}
void solve(){
    cout << fixed << setprecision(5);
    long double n, k, m;
    cin >> n >> k >> m;
    long double c, r, g, h;
    cin >> c >> r >> g >> h;
    long double f;
    cin >> f;
    long double a2, a3, a4;
    cin >> a2 >> a3 >> a4;
    long double s = a2+a3+a4;
    if (g==0 && h==0) cout  << 0.0;
    else if (g>0 || (h>0 && f>0)){
        long double ans = 1;
        while (c>g && m>=0){
            ans*= m/(m+3*k);
            m--;
            c--;
        }
        while (r>h && (m+(3-s)*k)>=0){
            ans*= (m+(3-s)*k)/(m+3*k);
            m--;
            r--;
        }
        cout << ans;
    }else{
        cout << fixed << setprecision(5) << 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--){
        solve();
    }
}