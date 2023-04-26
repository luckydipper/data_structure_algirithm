#include<bits/stdc++.h>
using namespace std;

int arr[12];

int N;

int do_calculate(int l, int r, int op){
    if(op == 0)
        return l + r;
    else if(op == 1)
        return l - r;
    else if(op == 2)
        return l * r;
    else if(op == 3)
        return l / r;
    else
        return -1;
}


//back_tracking solution
vector<int> picked;
int min_result = 0x7F7F7F7F;
int max_result = -0x7F7F7F7F; //1e-9 는 소수 자리수임. -1000

int num_op[4];

void operationPermutation(int to_pick){
    if(picked.size() == to_pick){
        int result = arr[0];
        for(int i = 0; i < picked.size(); i++){
            int op = picked[i];
            result = do_calculate(result, arr[i+1], op);
        }
        if(result < min_result )
            min_result = result;
        if(result > max_result )
            max_result = result;
        return;
    }
    for(int i = 0; i < 4; i++){
        if(num_op[i] == 0) continue;
        num_op[i]--;
        picked.push_back(i);
        operationPermutation(to_pick);
        num_op[i]++;
        picked.pop_back();
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(int i = 0; i < 4; i++)
        cin >> num_op[i];
    
    operationPermutation(N-1);

    cout << max_result << "\n" << min_result;
}