// knapsack처럼 마지막 index를 선택 할까 말까로 exhausted search 한다. 
// 거기에 caching 하면 됨. 
#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int cache[1001][1001];

// Like knapsack problem, we choose last index as parameter, 
// considering whether choosing that.
int LCS(int end_i, int end_j){
    
    if(end_i == 0 || end_j == 0)
        return 0;

    int &ret = cache[end_i][end_j];
    if(ret != -1)
        return ret;
    
    if(s1[end_i-1] == s2[end_j-1])
        return ret = 1 + LCS(end_i-1, end_j-1);
    
    return ret = max(LCS(end_i-1,end_j), LCS(end_i,end_j-1));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s1 >> s2;
    memset(cache, -1, sizeof(cache));
    cout << LCS(s1.size(),s2.size());
}