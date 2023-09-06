#include <bits/stdc++.h>

using namespace std;

int cnt_pivo1, cnt_pivo2;


int fibo1(int n){
    if( n == 1 || n == 2 ){
        cnt_pivo1++;
        return 1;
    }
    else 
        return fibo1(n-1) + fibo1(n-2);
}

int arr[41]; //ptr이니 8byte 만큼 잡히나? 
int fibo2(int n){
    for(int i = 3; i <= n; i++){
        cnt_pivo2++;
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    arr[1] = arr[2] = 1;
    int n;
    cin >> n;
    fibo1(n);
    fibo2(n);
    cout << cnt_pivo1 << " " << cnt_pivo2;
}