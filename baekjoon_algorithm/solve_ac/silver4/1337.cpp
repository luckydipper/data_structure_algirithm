// #include <bits/stdc++.h>
// 단순 구현 iterative 하게 순환시키기.
// 문제 읽어서 중복 없는것 체크 한 것 좋음. 
// 5를 기준으로 나눠서 알고리즘 짜는 것. -> 5개 이하의 box를 기준 잡고 전체 순환 시켜야함.
#include <iostream>
#include <algorithm>

int N;
int arr[50];
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i =0; i<N; i++){
        int tmp;
        cin >> arr[i];
    }
    sort(arr, arr+N);


    int pivot = -99;
    int nearest_cnt, biggest_cnt;
    nearest_cnt = biggest_cnt = 0;

    for(int i = 0; i < N; i++){
        for(int j = i; j < N && j < i+5; j++){
            if(arr[j] - arr[i] < 5 && nearest_cnt < 5)
                nearest_cnt++;
            // cout << arr[i] << ", " << arr[j] <<"\n";
            if(nearest_cnt > biggest_cnt )
                biggest_cnt = nearest_cnt;
        }
        nearest_cnt = 0;
    }
    cout << 5 - biggest_cnt;

    // if(N <= 5){
    //     for(int i = 0; i < N; i++){
    //         for(int k = 0; k < N-i; k++)
    //         // cout << arr[i+k] << " " << arr[i] << "\n";
    //         if(arr[i+k] - arr[i] < 5 && nearest_cnt<5)
    //             nearest_cnt++;
    //         if(nearest_cnt > biggest_cnt)
    //         biggest_cnt = nearest_cnt;
    //         nearest_cnt =1;
    //     }
    //     cout << 5 - nearest_cnt;
    //     return 0;
    // }
    // for(int i = 0; i < N-5; i++){
    //     for(int k = 0; k < 5; k++){
    //         // cout << arr[i+k] << " " << arr[i] << "\n";
    //         if(arr[i+k] - arr[i] < 5 && nearest_cnt<5)
    //             nearest_cnt++;
    //     }
    //     // cout << nearest_cnt;
    //     if(nearest_cnt > biggest_cnt)
    //         biggest_cnt = nearest_cnt;
    //     nearest_cnt =1;
    // }
    // for(auto a: arr)
    //     cout << a <<" ";
    // cout << "\n\n";
}