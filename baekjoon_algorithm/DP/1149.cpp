#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;

int arr[1001][3];
int cache[1001][3];

int min_cost(int last_index, int color){
    if(last_index == N)
        return arr[N][color];
    
    int & ret = cache[last_index][color];
    if(ret != -1)  
        return ret;
    
    ret = min(min_cost(last_index+1,(color+1)%3) + arr[last_index][color], 
              min_cost(last_index+1,(color+2)%3) + arr[last_index][color]);
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(cache,-1,sizeof(cache));

    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 0; j < 3; j++)
            cin >> arr[i][j];
    
    int result = 2147483647;
    for(int i = 0; i < 3; i++){
        result= min(result, min_cost(1,i));
    }
    cout << result;
}