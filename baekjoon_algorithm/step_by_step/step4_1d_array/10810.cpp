#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[101];

int main(){  
    cin >> N >> M;
    while(M--){
        int from, to, with;
        cin >> from >> to >> with;
        for(int i = from; i <= to; i++){
            arr[i] = with;
        }
    }
    for(int i = 1; i <= N; i++)
        cout << arr[i] << " ";
}