#include <bits/stdc++.h>
using namespace std;
int N, K;
int arr[300001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    cin >> arr[1];
    for(int i = 2; i <= N; i++){
        cin >> arr[i];
        arr[i-1] = arr[i] - arr[i-1];
    }
    sort(arr+1, arr+N);
    int result = 0;
    for(int i = 1; i < N-K+1; i++)
        result += arr[i];
    
    cout << result;
}