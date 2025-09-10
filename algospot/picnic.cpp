#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int C, n, m, result = 0;
bool is_friend[11][11];

vector< vector<int> > picked_elems;

// vector< pair<int,int> > aggregatePair(){}

// void pick(int n, vector<int>& picked, int to_pick, bool is_freind[11][11]){
//     if(to_pick == 0) {
//         bool is_correct_pair = true;
//         for(int i = 0; i < picked.size(); i++)
//             if(!is_friend[picked[0]][picked[1]])
//                 is_correct_pair = false;
//         if(is_correct_pair)
//             result++;
//         return;
//     }
//     int smallest = picked.empty() ? 0 : picked.back()+1;
//     for(int nxt = smallest; nxt <n; nxt++){
//         picked.push_back(nxt);
//         pick(n,picked,to_pick-1);
//         picked.pop_back();
//     }    
// }

// vector<pair<int,int>> makePair(vector<int>& not_selected){
//     int not_selected_length = not_selected.size();
//     vector<pair<int,int>> ret;

//     if(not_selected_length == 2){
//         ret = vector<pair<int,int>> { {not_selected[0], not_selected[1]}};
//         not_selected.clear();
//         return ret;
//     }
//     for(int first_pick_idx = 0; first_pick_idx < not_selected_length; first_pick_idx++){
//         for(int second_pick_idx = first_pick_idx+1; second_pick_idx < not_selected_length; second_pick_idx++){
//             ret.push_back({first_pick_idx, second_pick_idx});
//             not_selected.erase(not_selected.begin()+first_pick_idx);
//             not_selected.erase(not_selected.begin()+second_pick_idx);
//             auto remains = makePair(not_selected);
//             for(const pair<int,int> & remain: remains){
//                 ret.push_back(remain);
//             }
//         }
//     }
//     return ret;
// }


vector< vector<int> > bitmaskBasedCombination(int n){
    vector< vector<int> > ret;

    long long a=1;
    for(int i = 0; i < n; i++){
        a = a << 1;
    }
    cout <<"a " << a << "\n";

    for(long long i = 0; i < a; i++){
        vector<int> comp;
        long long tmp = i;
        while(tmp!=0){
            if(tmp%2)
                comp.push_back(1);
            else
                comp.push_back(0);
            tmp /= 2;
            //cout << "i = " << i << "\n";
        }
        ret.push_back(comp);
    }
    return ret;
}

vector<vector<int>> bitmaskBasedCombination(int n) {
    vector<vector<int>> ret;
    long long total = 1LL << n; // 2^n combinations
    for (long long i = 0; i < total; i++) {
        vector<int> comp;
        for (int j = n - 1; j >= 0; j--) {
            comp.push_back((i >> j) & 1);
        }
        ret.push_back(comp);
    }
    return ret;
}



int main(){
    cin >> C; 
    vector< vector<int> > a = bitmaskBasedCombination(C);
    for(const vector<int> &b: a){
        for(int c: b)
            cout << c << ", ";
        cout << "\n";
    }
    return 0;
    // while(C--){
    //     cin >> n >> m;
    //     int tmp1, tmp2;
    //     memset(is_friend, 0, sizeof(is_friend)/sizeof(bool));
    //     for(int i = 0; i < m; i++){
    //         cin >> tmp1 >> tmp2;
    //         is_friend[tmp1][tmp2] = is_friend[tmp2][tmp1] = true;
    //     }
    //     vector<int> not_selected;
    //     for(int i = 0; i < n; i++){
    //         not_selected.push_back(i);
    //     }
    //     vector<int> picked;
    //     pick(m, picked, 2, is_friend);
    //     cout << result;
    // }
}