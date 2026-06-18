#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>

using ll = long long;
using ull = unsigned long long;
using namespace std;

constexpr ll MOD = 1000000000039;
constexpr ll c = 179;

void solve(){
    string input_string;
    cin >> input_string;
    const ll input_string_length = input_string.size();
    vector<vector<ll>> hash_by_substr_length_and_start_pos(input_string_length+1, vector<ll>(input_string_length, -1));
    for (ll start_pos=0; start_pos<input_string_length; start_pos++){
        ll hash_curr_val = 0;
        for (ll curr_pos = start_pos; curr_pos<input_string_length; curr_pos++) {
            const auto curr_symb_val = static_cast<ll>(input_string[curr_pos] - 'a' + 1);
            hash_curr_val = (hash_curr_val*c + curr_symb_val)%MOD;
            hash_by_substr_length_and_start_pos[curr_pos-start_pos+1][start_pos] = hash_curr_val;
        }
    }

    // for (ll i=0; i<=input_string_length; i++) {
    //   for (ll j=0; j<input_string_length; j++) {
    //     cout << hash_by_substr_length_and_start_pos[i][j] << " ";
    //   }
    //   cout << '\n';
    // }

    ll ans = input_string_length + 1;
    for (ll length = 1; length<=input_string_length; length++) {
        map<ll, ll> cnt_by_hash;
        map<ll, ll> last_ind_by_hash;
        ll max_cnt = 0;
        for (ll start = 0; start < input_string_length; start++) {
            const auto hash = hash_by_substr_length_and_start_pos[length][start];
            if (hash == -1) continue;

            if (!last_ind_by_hash.contains(hash) || last_ind_by_hash[hash] <= start - length) {
                cnt_by_hash[hash]++;
                last_ind_by_hash[hash] = start;
                max_cnt = max(max_cnt, cnt_by_hash[hash]);
            }
        }

        ans = min(ans, input_string_length - (length-1)*max_cnt + length);
    }
    cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t --> 0){
    solve();
  }
}

//  g++ -std=c++20 1.cpp -o a.out && ./a.out
