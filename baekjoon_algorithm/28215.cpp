// 문제 제대로 읽기 
// 집 중에 하나가 대피소가 되는구나..
        
#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getDistance(int x, int y, int x_, int y_){
    return abs(x_ - x) + abs(y_ - y);
}

int N, K, min_dist = 99999999;
vector< pair<int,int> > arr;
vector<int> picked_idx;

void combination(const vector< pair<int,int> >& arr, int n){
    if(picked_idx.size() == n){
        vector<int> min_dist_arr;

        // for(const auto& pivot_idx: picked_idx){
        //     for(const auto& it: arr){
        //         int dist = getDistance(arr[pivot_idx].first, arr[pivot_idx].second, it.first, it.second);
        //         if( dist > max_dist){
        //             max_dist = dist;
        //         }
        //     }
        // }

        for(const auto& it: arr){
            int mm = 9999999;
            for(const auto& pivot_idx: picked_idx){
                int dist = getDistance(arr[pivot_idx].first, arr[pivot_idx].second, it.first, it.second);
                if( mm > dist){
                   mm = dist; 
                }
            }
            min_dist_arr.push_back(mm);
        }


        int max_dist = *max_element(min_dist_arr.begin(), min_dist_arr.end() );

        //cout << "md: " << max_dist << "\n";
        if(min_dist > max_dist){
            min_dist = max_dist;
        }
        return;
    }
    int smallest_idx = picked_idx.empty() ? 0 : picked_idx.back()+1;
    for(int i = smallest_idx; i < arr.size(); i++){
        picked_idx.push_back(i);
        combination(arr,n);
        picked_idx.pop_back();
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int tmp_x, tmp_y;
        cin >> tmp_x >> tmp_y;
        arr.push_back(make_pair(tmp_x, tmp_y));
    }
    combination(arr, K);
    cout << min_dist;
}

// combination 구현방법
// - backtracking 
// - bit masking
