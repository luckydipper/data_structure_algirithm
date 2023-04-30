#include <bits/stdc++.h>
using namespace std;

int N;
int ability_map[21][21];
int result_min = 987654321;


vector<int> start_picked;


void halfCombination(int len_ability_array){
    if(start_picked.size() == len_ability_array/2)
    {
        int start_sum = 0, link_sum = 0;

        vector<bool> is_index_link_picked;
        for(int i = 0; i < len_ability_array; i++)
            is_index_link_picked.push_back(true);

        for(int idx_x: start_picked){
            is_index_link_picked[idx_x] = false;
            for(int idx_y: start_picked)
                start_sum += ability_map[idx_x][idx_y];
        }
        vector<int> linked_picked_index;
        for(int i = 0; i < len_ability_array; i++)
            if(is_index_link_picked[i])
                linked_picked_index.push_back(i);
        
        for(int idx_x: linked_picked_index){
            for(int idx_y: linked_picked_index)
                link_sum += ability_map[idx_x][idx_y];
        }

        if(result_min > abs(start_sum- link_sum))
            result_min = abs(start_sum-link_sum);
        return;
    }
    int smallest = start_picked.empty()? 0 : start_picked.back()+1;

    for(int i = smallest; i< len_ability_array; i++){
        start_picked.push_back(i);
        halfCombination(len_ability_array);
        start_picked.pop_back();
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> ability_map[i][j];
    
    halfCombination(N);

    cout << result_min;

}