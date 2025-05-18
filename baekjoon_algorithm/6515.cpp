//c++ find
//map iteration first last
// memset 0x7f
// histogram <-> bin <-> elem 
#include <iostream>
#include <map>
//#include <pair>
#include <algorithm>
using namespace std;
int n, q;
int ascend_arr[100001];
map<int, int> hist;
map<int, int> elem2idx; // bin

int main(){
    cin >> n >> q;
    vector<int> elems; 
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        elems.push_back(tmp);
        hist[tmp]++;
    }
    elem2idx[elems[0]] = 0;
    int idx_cnt = 0;
    for(int i = 0; i < n-1; i++){
        if(elems[i] != elems[i+1])
            elem2idx[elems[i+1]] = ++idx_cnt;
    }
    // cout << "nhist \n\n";
    // for(auto h: elem2idx)
    //     cout << h.first <<", " << h.second << " ";
    // cout << "\n\nkeys";
    // for(auto k: keys)
    //     cout << k << " ";
    int sumation = 0;
    vector<int> patial_sum;
    for(auto h: hist){
        sumation += h.second;
        patial_sum.push_back(sumation);
        // cout << sumation << " ";
    }

    int first_survey_key, last_survey_key;
    for(int i = 0; i < q; i++){
        int first, last;
        cin >> first >> last;
        //find(keys, elems[first]);
        int low_idx = elem2idx[elems[first]];
        int high_idx = elem2idx[elems[last]];

        biggest_hist = -1111111;
        
        int cnt_low_edge sumation[low_idx] - first;
        int cnt_high_edge last - sumation[high_idx-1];

        for(int j = low_idx; j<= high_idx; j++){

        }
    }
}