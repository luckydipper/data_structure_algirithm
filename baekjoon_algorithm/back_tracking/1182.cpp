#include <bits/stdc++.h>
using namespace std;
int N, S;
int arr[21];

int result, sum_patrial;
vector<int> picked;
// N개 중 picked_num 만큼 골랐음으로 해야 됨. 
void combination(int to_pick){
    if(picked.size() == to_pick){
        sum_patrial = 0;
        for(int idx : picked)
            sum_patrial += arr[idx];

        if(S == sum_patrial)
            result++;
        return;
    }
    int smallest = picked.empty() ? 0 : picked.back()+1;
    for(int i = smallest; i < N; i++){
        picked.push_back(i);
        combination(to_pick);
        picked.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S;
    for(int i = 0; i < N; i++ )
        cin >> arr[i];
    
    for(int i = 1; i <= N; i++)
        combination(i);
    
    cout << result;
    return 0;
}