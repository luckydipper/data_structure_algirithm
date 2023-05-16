#include <bits/stdc++.h>
using namespace std;
int arr[501][501];
int cache[501][501];
int n;

//sub problem의 수 N^2 반복문 x 그러므로 O(N^2)
int maxSumPath(int y, int x){
    if(x > y || y > n)
        return 0;
    if(y == n)
        return arr[y][x];
    
    int &ret = cache[y][x];
    if(ret != -1)
        return ret;
    
    ret = arr[y][x] + max(maxSumPath(y+1,x+1), maxSumPath(y+1,x)) ;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(cache, -1, sizeof(cache));

    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> arr[i][j];

    cout << maxSumPath(1,1);
}