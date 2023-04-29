#include <bits/stdc++.h>
using namespace std;

int N;
int ability_map[21][21];
vector<int> ability_arr;
vector<int> is_used[21];
int result_min = 987654321;

// vector<vector<int>> selecteds;
// vector<int> selected;
// void selectOneORZero(int N){
//     if(selected.size() == M){
//         selecteds.push_back(selected);
//     }
//     for(int i = 0; i < N; i++){
//         selected.push_back(0)
//     }
// }

vector<vector<int>> spanZeroOneMatrix(int num){
    vector<vector<int>> result;
    for(int i = 0; i <= num; i++ ){
        vector<int> tmp(num);
        for(int j = 0; j < i; j++)
            tmp[j] = 1;
        result.push_back(tmp);
    }
    return result;
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


    sort(ability_arr.begin(),ability_arr.end());

    for(int i = 0; i <= ability_arr.size(); i++ ){
        vector<int> tmp(ability_arr.size());
        //fill(tmp.begin(),tmp.end(),0)
        for(int j = 0; j < i; j++)
            tmp[j] = 1;
        
        is_used[i] = tmp;
    }


    for(int num = 2; num <= ability_arr.size(); num++){
        do{
            vector<int> picked_person;
            for(int i = 0; i < ability_arr.size(); i++){
                if(is_used[num][i] == 1)
                    picked_person.push_back(ability_arr[i]);
            }

            vector<vector<int>> start_or_rink = spanZeroOneMatrix(picked_person.size());
            for(int num_start = 1; num_start <= picked_person.size(); num_start++){
                int zero = 0, one = 0;
                do{
                    for(int i = 0; i < start_or_rink.size();i++){
                        if(start_or_rink[num_start][i] == 1)
                            one += picked_person[i];
                        else if(start_or_rink[num_start][i] == 0)
                            zero += picked_person[i];
                    }
                    if(result_min  > abs(one - zero)){
                        for(int i : picked_person)
                            cout << i << " ";
                        cout << "\n";
                        for(int i: start_or_rink[num_start])
                            cout << i;
                        cout << "\n\n";
                        result_min = abs(one - zero); 
                    }
                }while(prev_permutation(start_or_rink[num_start].begin(), start_or_rink[num_start].end() ));
            }
        }while(prev_permutation(is_used[num].begin(), is_used[num].end() ));
    }
    cout << result_min;
}