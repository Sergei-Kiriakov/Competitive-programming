#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

using ll = long long;

void solve(){
    string a, b;
    cin >> a >> b;
    map<char, ll> cnt_a;
    map<char, ll> cnt_b;
    for (auto c: a) {
        cnt_a[c]++;
    }
    for (auto c: b) {
        cnt_b[c]++;
    }
    string ans;
    for (char c = 'a'; c <= 'z'; c++){
        ll mn = max(cnt_a[c], cnt_b[c]);
        for (int i=0; i<mn; i++){
            ans.push_back(c);
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
