#include <bits/stdc++.h>
using namespace std;

int N;
int ability_map[21][21];
vector<int> ability_arr;
int result_min = 987654321;
//permutation으로 구현 해보자.

bool is_picked[21];
vector<int> picked_index;
vector<int> sum_partial;

//combination 이네
void update_sum_partial(int n, int m){
    if(picked_index.size() == m){
        int result = 0;
        for(int idx: picked_index){
            cout << idx << " ";
            result += ability_arr[idx];
        }
        cout << "\n";
        sum_partial.push_back(result);
        return;
    }
    int smallest = picked_index.empty() ? 1 : picked_index.back()+ 1;

    for(int i = smallest; i < n; i++){
        picked_index.push_back(i);
        update_sum_partial(n, m);
        picked_index.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> ability_map[i][j];

    for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++)
            ability_arr.push_back(ability_map[i][j] + ability_map[j][i]);

    sort(ability_arr.begin(), ability_arr.end());
    
    for(int i = 0; i < ability_arr.size(); i++){
        update_sum_partial(ability_arr.size(), i);
    }

    for(int i : sum_partial)
        cout << i << " ";
    cout << "\n";
    sort(sum_partial.begin(), sum_partial.end());

}