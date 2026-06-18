#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>

using ll = long long;
using ull = unsigned long long;
using namespace std;

constexpr ll MOD = 1000000039;
constexpr ll c = 179;

namespace {

struct HorizontalSegment {
    ll left_border_pos;
    ll length;
    ll height;
};

HorizontalSegment FindPlacementSegment(const map<ll, HorizontalSegment>& hor_seg_by_left_border_pos, ll new_seg_left_border_pos){
    auto find_iter = hor_seg_by_left_border_pos.upper_bound(new_seg_left_border_pos);
    find_iter--;
    return find_iter->second;
}

void AddNewSegment(map<ll, HorizontalSegment>& hor_seg_by_left_border_pos, ll new_seg_length, ll new_seg_left_border_pos, ll new_seg_height) {
    const auto placement_segment = FindPlacementSegment(hor_seg_by_left_border_pos, new_seg_left_border_pos);
    hor_seg_by_left_border_pos.erase(placement_segment.left_border_pos);
    std::vector<HorizontalSegment> segments;
    if (placement_segment.left_border_pos > 0){
        const auto left_seg = FindPlacementSegment(hor_seg_by_left_border_pos, placement_segment.left_border_pos - 1);
        hor_seg_by_left_border_pos.erase(left_seg.left_border_pos);
        segments.push_back(left_seg);
    }
    if (placement_segment.left_border_pos < new_seg_left_border_pos){
        segments.push_back({.left_border_pos = placement_segment.left_border_pos, .length =  new_seg_left_border_pos - placement_segment.left_border_pos, .height = placement_segment.height});
    }
    segments.push_back({.left_border_pos = new_seg_left_border_pos, .length =  new_seg_length, .height = placement_segment.height + new_seg_height});
    if (placement_segment.left_border_pos + placement_segment.length > new_seg_left_border_pos+new_seg_length){
        segments.push_back({.left_border_pos = new_seg_left_border_pos+new_seg_length, .length =  placement_segment.left_border_pos + placement_segment.length - (new_seg_left_border_pos+new_seg_length), .height = placement_segment.height});
    }
    if (placement_segment.left_border_pos + placement_segment.length <  MOD*MOD+MOD) {
        const auto right_seg = FindPlacementSegment(hor_seg_by_left_border_pos, placement_segment.left_border_pos + placement_segment.length);
        hor_seg_by_left_border_pos.erase(right_seg.left_border_pos);
        segments.push_back(right_seg);
    }
    while (segments.size() > 1){
        const auto last_segment = segments.back();
        segments.pop_back();
        const auto pre_last_segment =  segments.back();
        if (last_segment.height == pre_last_segment.height) {
            segments.pop_back();
            segments.push_back({.left_border_pos = pre_last_segment.left_border_pos, .length = pre_last_segment.length+last_segment.length, .height = last_segment.height});
        } else {
            hor_seg_by_left_border_pos[last_segment.left_border_pos] = last_segment;
        }
    }
    const auto last_segment = segments.back();
    hor_seg_by_left_border_pos[last_segment.left_border_pos] = last_segment;
}

void solve(){
    ll n;
    cin >> n;
    map<ll, HorizontalSegment> hor_seg_by_left_border_pos;
    hor_seg_by_left_border_pos[0] = {.left_border_pos = 0, .length = MOD*MOD+MOD, .height=0};
    for (int i=0; i<n; i++){
        char c;
        ll new_seg_length, new_seg_left_border_pos, new_seg_height = 1;
        cin >> c >> new_seg_length >> new_seg_left_border_pos;
        if (c == '|') {
            swap(new_seg_length, new_seg_height);
        }
        const auto placement_seg = FindPlacementSegment(hor_seg_by_left_border_pos, new_seg_left_border_pos);
        if (placement_seg.left_border_pos+placement_seg.length < new_seg_left_border_pos + new_seg_length) {
            // cerr << "\n" << placement_seg.left_border_pos << " " << placement_seg.length << " " <<   placement_seg.height << '\n';
            cout << "U";
            continue;
        }
        AddNewSegment(hor_seg_by_left_border_pos, new_seg_length, new_seg_left_border_pos, new_seg_height);
        cout << "S";
    }
}

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
