#include <bits/stdc++.h>
using namespace std;
int n, x;
int arr[100001];
int result;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    sort(arr,arr+n);
    int* begin_arr = arr;
    int* end_arr = begin_arr+n;
    
    while(begin_arr != end_arr-1){
        int sum_ = *begin_arr + *(end_arr-1);
        if(sum_ > x)
            end_arr--;
        else if(sum_ < x)
            begin_arr++;
        else{
            result++;
            begin_arr++;
        }
    }
    cout << result; 
}