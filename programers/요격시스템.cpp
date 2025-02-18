//TODO: Strict Weak Ordering 만족 해야함 

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;
// greedy 문제인데, 끝나는 순서대로 정렬하자. 

// bool comp(const vector<int>& a, const vector<int>& b){
//     assert(a.size() == 2);
//     assert(b.size() == 2);
    
//     if(a[1] < b[1])
//         return true;
//     else if(a[0] < b[0])
//         return true;
//     else
//         return false;
// }

bool comp(const vector<int>& a, const vector<int>& b){
    assert(a.size() == 2);
    assert(b.size() == 2);
    
    return a[1] < b[1];
    //if(a[1] < b[1])
    // return ture; -> else false 
}
int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end(), comp);
    int tmp_end = targets[0][1];
    // for(auto target: targets){
    //     cout << target[0] << ", " << target[1] << "\n";
    // }
    for(int i = 0; i < targets.size(); i++){
        int target_begin_time = targets[i][0];   
        if(target_begin_time >= tmp_end){
            answer++;
            tmp_end = targets[i][1];
            // cout << tmp_end << "\n";
        }
    }
    return answer;
}