#include <bits/stdc++.h>
using namespace std;
int N, C, result;
int arr[31];
//int cache[31][1000000001]; //index , capacity cache[31][1000000001]
// memory를 너무 많이 쓴다. 

int consider(int index, int capacity){
    if(index == 1){
        if(arr[index] > capacity)
            return 1; // 아무 것도 선택하지 않는 경우의 수 
        else
            return 2; // 아무것도 선택하지 않거나 한개 선택하는 경우의 수 
    }
    // index 물질을 가져가거나 
    if(arr[index] > capacity){
        // if(cache[index-1][capacity])
        //     return cache[index-1][capacity] + 1;
        // cache[index-1][capacity] = consider(index-1, capacity);
        return consider(index-1, capacity);
    }
    else{
        
        // if(cache[index-1][capacity] == -1)
        //     cache[index-1][capacity] = consider(index-1, capacity);
        // if(cache[index-1][capacity-arr[index]] == -1)
        //     cache[index-1][capacity-arr[index]] = consider(index-1, capacity-arr[index]);
        
        return consider(index-1, capacity) + consider(index-1, capacity-arr[index]) ;
    }
}


int main(){
    cin >> N >> C;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    //sort(arr, arr+N);
    //int** cache(new int* [31]);  //unique_ptr<int>
    // for(int i = 0 ; i < 31; i++)
    //     cache[i] = new int[1000000000];
    
    // for(int i =0; i < 31; i++){
    //     fill(cache[i], cache[i]+1000000000, -1);
    // }

    cout << consider(N, C);

    // for(int i = 0 ; i < 31; i++)
    //     delete[] cache[i];
    // delete[] cache;
}