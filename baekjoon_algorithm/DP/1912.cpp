#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100001];
int max_continus_end_with[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    max_continus_end_with[0] = arr[0];
    for(int i = 1; i < n; i++){
        if(max_continus_end_with[i-1] > 0)
            max_continus_end_with[i] = arr[i] + max_continus_end_with[i-1];
        else
            max_continus_end_with[i] = arr[i];
        // if(arr[i] >= 0)
        //     max_continus_end_with[i] += (arr[i] + max_continus_end_with[i-1]);
        // if(arr[i] + max_continus_end_with[i-1] <= 0)
        //     max_continus_end_with[i] = arr[i];
        // else if(arr[i] +max_continus_end_with[i-1] > 0)
        //     max_continus_end_with[i] = max_continus_end_with[i-1] ;
    }
    int max_result = -2147483640;
    for(int i = 0; i <n; i++){
        if(max_continus_end_with[i] > max_result)
            max_result = max_continus_end_with[i];
    }
    cout << max_result;
}