// Meet In The Middle : brute force를 쓸 수 없을 만큼 클 때
// 절반 나눠서 찾는 기술
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, C;
int arr[31];

//back tracking 보단 dfs로 구현하는 것이 powerset 구하기 쉬움.
vector<ll> picked;
void combination_index(vector<ll>& sum_super_set, int begin_index, int end_index, int to_pick_size){
    if(picked.size() == to_pick_size){
        ll result = 0;
        for(int i : picked)
            result += arr[begin_index+i];
        sum_super_set.push_back(result);
        return;
    }
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    for(int i = smallest; i < end_index-begin_index; i++){
        picked.push_back(i);
        combination_index(sum_super_set,begin_index, end_index, to_pick_size);
        picked.pop_back();
    }
}

vector<ll> spanArrBeginEnd(int begin, int end){
    vector<ll> sum_super_set;
    for(int i = 0; i <= end - begin; i++){
        picked.clear();
        combination_index(sum_super_set, begin,end, i);
    }
    return sum_super_set;
}

int main(){
    cin >> N >> C;

    for(int i = 0; i < N; i++)
        cin >> arr[i];
    vector<ll> front_case = spanArrBeginEnd(0, N/2);
    vector<ll> back_case = spanArrBeginEnd(N/2, N);

    sort(back_case.begin(), back_case.end());
    int result = 0;
    for(ll f : front_case){
        auto end = upper_bound(back_case.begin(), back_case.end(), C-f);
        result += end - back_case.begin();
    }
    // for(int f : front_case)
    //     cout << f << " ";
    // cout << "\n";
    // for(int b : back_case)
    //     cout << b << " ";
    // cout << "\n---------------------\n";
    cout << result;
}
