#include <bits/stdc++.h>
using namespace std;
int N;
int arr[301];
int cache[301][3];
const int INF = -1e6;

// i번째에 1을 j번 연속 사용했을 때, i ~ N까지 최대 점수.
int max_score(int i, int j){
    if(j >= 3 || i > N)
        return 0;

    int &ret = cache[i][j]; // j까지 caching 해야 하나?
    
    if(ret != -1)
        return ret;

    // max_score(i+2, 0)이 아니다.
    ret = arr[i] + max(max_score(i+1, j+1), max_score(i+2, 1)); 
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    memset(cache, -1, sizeof(cache));
    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    cout << max_score(0,0); //max(max_score(1,1), max_score(2,0));
}