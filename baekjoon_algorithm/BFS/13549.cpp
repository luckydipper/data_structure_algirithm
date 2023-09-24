#include <bits/stdc++.h>

using namespace std;
int N, K;
int arr[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;

    memset(arr, -1, sizeof(arr));
    queue<int> q;
    q.push(N);
    arr[N] = 0;

    while(!q.empty()){
        int here = q.front();
        q.pop();
        if(here == K){
            cout << arr[here];
            break;
        }
        for(int twice = 2*here; twice <= 100000 && arr[twice] == -1; twice*=2){
            arr[twice] = arr[here];
            q.push(twice);
        }
        int there[2] = {here-1, here+1}; // -1 -> 1 순서로 해야지 뒤에 영향을 받지 않음. 아니면 min 
        for(int i = 0; i < 2; i++){
            if(there[i] < 0 || 100000<there[i] || arr[there[i]] != -1)
                continue;
            arr[there[i]] = arr[here] + 1;
            q.push(there[i]);
        }
    }
}