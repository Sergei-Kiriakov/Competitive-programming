#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <bit>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <bitset>

using ll = long long;
using ull = unsigned long long;
using namespace std;

constexpr ll MOD = 1000000039;
constexpr ll c = 179;

namespace {

void log_vec(const vector<ull>& vec) {
    for (const auto& elem: vec) {
        cerr << elem << " ";
    }
    cerr << "\n";
}

std::vector<ull> generate_possible_candidates(ull column, ull max_num){
    const auto pair_mask = max_num^column;
    const auto candidates_count = popcount(pair_mask);
    std::vector<ull> possible_candidates;
    possible_candidates.reserve(candidates_count);

    std::vector<ull> ones_pos;
    for (int i=0; i<popcount(max_num); i++){
        if (column&(1<<i)) {
            ones_pos.push_back(i);
        }
    }

    for (int i=0; i< (1<<popcount(column)); i++) {
        auto cand = pair_mask;
        for (int k=0; k<popcount(column); k++){
            if (i&(1<<k)){
                cand += 1<<ones_pos.at(k);
            }
        }
        possible_candidates.push_back(cand);
    }
    return possible_candidates;
}

std::vector<ull> find_existed_candidates(
    const std::vector<ull>& poss_cand, 
    const std::unordered_map<ull, vector<ull>>& num_pos, ull ind) {
    std::vector<ull> result;
    for (const auto cand: poss_cand) {
        const auto find_iter = num_pos.find(cand);
        if (find_iter == num_pos.end()){
            continue;
        }
        const auto& ex_cands = find_iter->second;
        for (const auto ex_cand: ex_cands) {
            if (ex_cand == ind) {
                continue;
            }
            result.push_back(ex_cand);
        }
    }
    return result;
}

void solve(){
    ull n, m;
    cin  >>  n >> m;
    vector<string> lines(n);
    for (int i=0; i<n; i++){
        cin >> lines[i];
    }

    vector<ull> columns(m, 0);
    unordered_map<ull, vector<ull>> numbers_pos;
    numbers_pos.reserve(1<<20);
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (lines[j][i] == '1') {
                columns[i] += 1<<j;
            }
        }
        numbers_pos[columns[i]].push_back(i);
    }

    const ull max_num = (1<<n) - 1;
    const auto default_ans = pair<ull, ull>{MOD, MOD};
    auto ans = default_ans;
    for (int i=0; i<m; i++){
        const auto column = columns[i];
        if (column == 0 || column == max_num) {
            continue;
        }
        if (popcount(column) > m/2) {
            continue;
        }

        const auto poss_cands = generate_possible_candidates(column, max_num);
        // log_vec(poss_cands);
        const auto ex_cands = find_existed_candidates(poss_cands, numbers_pos, i);
        // log_vec(ex_cands);
        if (ex_cands.size() > 1) {
            cout << "No\n";
            return;
        }
        if (ex_cands.size() == 0) {
            continue;
        }
        const auto ex_cand = ex_cands.at(0);

        if ((columns.at(ex_cand) + column > max_num) && !(columns.at(ex_cand) == max_num && popcount(column)==1)) {
            cout << "No\n";
            return;
        }
        const auto first = min(static_cast<ull>(i), ex_cand);
        const auto second = max(static_cast<ull>(i), ex_cand);
        const auto new_ans = pair<ull, ull>{first, second};
        if (ans != default_ans && ans !=new_ans){
            cout << "No\n";
            return;
        }
        ans = new_ans;
    }
    if (ans==default_ans) {
        cout << "No\n";
        return;
        // throw std::logic_error("unexpected behaviour");
    }
    cout << "Yes\n";
    cout << ans.first + 1 << " " << ans.second + 1 << "\n";
}

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t --> 0){
    solve();
  }
}

//  g++ -std=c++20 1.cpp -o a.out && ./a.out
