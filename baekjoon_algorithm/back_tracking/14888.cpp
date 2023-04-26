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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    
    vector<int> spaned_operations;
    
    for(int i = 0; i < 4; i++){
        int tmp;
        cin >> tmp;
        while(tmp--)
            spaned_operations.push_back(i);
    }

    int min_result = 0x7F7F7F7F;
    int max_result = -0x7F7F7F7F; //1e-9 는 소수 자리수임. -1000
    do{
        int result = arr[0];
        for(int i = 0; i < spaned_operations.size(); i++){
            int op = spaned_operations[i];
            result = do_calculate(result, arr[i+1], op);
        }
        if(result < min_result )
            min_result = result;
        if(result > max_result )
            max_result = result;

    }while(next_permutation(spaned_operations.begin(), spaned_operations.end()));

    cout << max_result << "\n" << min_result;
}