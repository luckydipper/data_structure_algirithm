#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[101];

int main(){  
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        arr[i] = i;
    
    while(M--){
        int from, to;
        cin >> from >> to;
        swap(arr[from],arr[to]);
    }
    for(int i = 1; i <= N; i++)
        cout << arr[i] << " ";
}