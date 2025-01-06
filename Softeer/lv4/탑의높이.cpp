
//TODO: 처음에 정한 피라미드의 꼭대기가 계속해서 꼭대기 인줄 알음
// 피라미드의 중심을 제외한 왼쪽과 오른쪽으로 기울어진 피라미드를 만들 수 있음.

// 교훈: 다음부턴 예제에 나온 것은 머리속에 생각해고 하기 
#include<iostream>
#include<bits/stdc++.h>
// 8:50 시작 11:00 끝
// back tracking? 
// greedy? lagest one 
// max (heap) 가장 큰 index중에서 주변 살펴 
// log N *
// K가 N보다 클 때 K/N만큼 각칸이 ㅂㅂ올라가야 하는가? o
// pyramid first last 
using namespace std;

int N, result, roi_idx;
long long K;
int arr[1001];

int main(int argc, char** argv)
{
    N = result = roi_idx = -1;
    cin >> N >> K;
    for(int i =0; i<N; i++){
        cin >> arr[i];
        
        if(arr[i] > result){
            result = arr[i];
            roi_idx = i;
        }
    }

    int pyramid_first, pyramid_last, pyramid_size;
    pyramid_first = pyramid_last = roi_idx;


    while(K > pyramid_size){
        if(pyramid_first == 0 && pyramid_last == N) //is complete pyramid
            break;

        while(pyramid_first > 0){
            if (arr[roi_idx] - arr[pyramid_first] != roi_idx - pyramid_first){
                pyramid_first++;
                break;
            }
            pyramid_first--;
        }
        
        while(pyramid_last < N ){
            if (arr[roi_idx] - arr[pyramid_last] != pyramid_last - roi_idx){
                pyramid_last--;
                break;
            }            
            pyramid_last++;
        }


        int l_pyramid_size = roi_idx - pyramid_first ;
        int r_pyramid_size = pyramid_last - roi_idx ;


        //stack
        if(l_pyramid_size < r_pyramid_size){
            pyramid_size = l_pyramid_size;
            for(int i = pyramid_first; i <= roi_idx; i++)
                arr[i]++;
        }
        else if (l_pyramid_size > r_pyramid_size){
            pyramid_size = r_pyramid_size;
            for(int i = roi_idx; i <= pyramid_last; i++)
                arr[i]++;
        }
        else{
            pyramid_size = pyramid_last - pyramid_first;
            for(int i = pyramid_first; i <= pyramid_last; i++)
                arr[i]++;
        }
        K -= pyramid_size;

        for(int i = 0; i < N; i++)
            cout <<arr[i] << ", ";
        cout << "\n";
        cout << pyramid_first << " " << pyramid_last << "---\n";
        
        result++;
    }
    long long floor_size = K/pyramid_size;
    result += floor_size;
    // cout << roi_idx - pyramid_first << ", " << K <<"\n";
    // if(roi_idx - pyramid_first + 1 <= K || pyramid_last - roi_idx +1 <= K)
    //     result++;
    cout << result;
    return 0;
}