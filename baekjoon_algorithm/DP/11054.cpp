#include<bits/stdc++.h>
using namespace std;

int N;
int arr[1001];
int increase_cache[1001];
int decrease_cache[1001];

int findAfterLDS(int here){
    // There is no base case.
    int &ret = increase_cache[here];
    
    if(ret != -1)
        return ret;
    ret = 1;

    for(int there = here+1; there <= N; there++)
        if(arr[here] > arr[there])
            ret = max(ret, findAfterLDS(there)+1);
    
    return ret;
}

//이전 원소까지 가장 적은 원소의 갯수 
int findBeforeLIS(int here){
    // There is no base case.
    int &ret = decrease_cache[here];
    if(here == 1)
        return ret = 1;
    if(ret != -1)
        return ret;
    ret = 1;
    for(int there = here-1; there >= 1; there--)
        if(arr[there] < arr[here])
            ret = max(ret, findBeforeLIS(there)+1);
    
    return ret;
}


int main(){
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    memset(increase_cache, -1, sizeof(increase_cache));
    memset(decrease_cache, -1, sizeof(decrease_cache));
    // arr[0] = -2147483647;
    // cout << findLIS(0)-1 << "\n";
    // arr[0] = 2147483647;
    // cout << findLDS(0)-1;
    int result = -2147483647;

    // int a;
    // cin >> a;
    // cout << findLIS(a);
    for(int i = 1; i <= N; i++)
        result = max(result, findAfterLDS(i)+findBeforeLIS(i)-1);
    
    // cout << findBeforeLIS(8)+findAfterLDS(8);
    cout << result;
}