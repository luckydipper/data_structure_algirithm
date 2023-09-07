#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1001];
int max_liter_to[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    max_liter_to[0] = arr[0] = -214748365;
    max_liter_to[1] = arr[1];
    max_liter_to[2] = arr[2];
    for(int i = 1; i <= n; i++)
        max_liter_to[i] = max( max(arr[i] + arr[i-1] + max_liter_to[i-3], arr[i] + max_liter_to[i-2]), max_liter_to[i-1]);
    
    cout << max_liter_to[n];   
}

