#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
void input(vector <ll> &val, vector <vector <pair <int, int> > > &roads, int ind){
    ll m, g;
    cin >> m >> g;
    for (int i=0; i<m; i++){
        ll x;
        cin >> x;
        val[x]++;
    }
    for (int i=0; i<g; i++){
        int x, y;
        cin >> x >> y;
        roads[ind].push_back({x, y});
    }
}
int main(){
    ll n;
    cin >> n;
    vector <ll> vals(n+1, 0);
    vector < vector <pair <int, int> > > roads(4);
    for (int i=0; i<4; i++){
        input(vals, roads, i);
    }
    for (int i=0; i<4; i++){
        ll ans = 0;
        for (auto e:roads[i]){
            ans+=vals[e.second]+vals[e.first];
        }
        cout << ans << " ";
    }
}
