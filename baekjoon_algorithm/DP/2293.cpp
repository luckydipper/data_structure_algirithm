#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[101];

// using from "start" index, the case of making "target".
int cache[101][10001];

int getCount(int start, int target){
    if(start == n || target < 0)
        return 0;

    int& ret = cache[start][target];

    if(target == 0)
        return ret = 1;
    if(ret != 0)
        return ret;

    if(start == n-1) {// 마지막 원소로 딱 나눠지는 경우, 1 아니면 0
        if(target / arr[n-1])
            return ret = 1;
        else
            return ret = 0;
    }
    // case of not using starting index
    ret += getCount(start+1,target);

    // case of using i starting index
    int max_usage_starting_index = target/arr[start];
    for(int i = 1; i <= max_usage_starting_index; i++)
        ret += getCount(start+1, target - arr[start]*i); //2를 한번 쓰고 다신 안쓴다는 마인드로 가야지 mutually exclusive 가능.

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for(int i =0; i <n; i++)
        cin >> arr[i];

    sort(arr, arr+n);
    reverse(arr,arr+n);

    cout << getCount(0,k) << "\n";

    // for(int i =0; i <n; i++)
    //     cout << arr[i] << " ";
    // cout << "\n";
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= k; j++)
    //         cout << cache[i][j] << " ";
    //     cout << "\n";
    // }
}