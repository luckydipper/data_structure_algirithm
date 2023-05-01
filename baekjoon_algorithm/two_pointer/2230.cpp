// 수 고르기
#include<bits/stdc++.h>
using namespace std;
int N, M;
int arr[100001];
int smallest_result = 2100000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0; i< N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);

    int* begin_ptr = arr;
    int* end_ptr = arr;

    while(end_ptr != (arr+N) && begin_ptr != (arr+N)){
        int offset = *end_ptr -*begin_ptr;
        if( offset > M){
            if(smallest_result > offset)
                smallest_result = offset;
            begin_ptr++;
        }
        else if( offset < M)
            end_ptr++;
        else if( offset == M){
            cout << M;
            return 0;
        }   
    }
    cout << smallest_result;
}