#include <bits/stdc++.h>
using namespace std;
bool is_submited[31];

int main(){
    for(int i = 0; i < 28; i++){
        int idx;
        cin >> idx;
        is_submited[idx] = true;
    }
    for(int i = 1; i <= 30; i++){
        if(!is_submited[i])
            cout << i << " \n";
    }
}