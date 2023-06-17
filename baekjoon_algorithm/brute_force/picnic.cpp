#include <bits/stdc++.h>
using namespace std;

int C, n, m;
bool adj_mat[11][11];
int result;
bool is_used[11];

void countZeroTo(int here){
    if(here == 0) {result++; return;}
    if(is_used[here]) return;
    is_used[here] = true;
    for(int there = 0; there <n; there++){
        if(!adj_mat[here][there]) continue;
        if(is_used[there]) continue;
        is_used[there] = true;
        countZeroTo(here-1);
        is_used[there] = false;
    }
    is_used[here] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> C;
    while(C--){
        result = 0;
        memset(adj_mat, 0, sizeof(adj_mat));
        cin >> n >> m;
        while(m--){
            int n1, n2;
            cin >> n1 >> n2;
            adj_mat[n1][n2] = 1;
            adj_mat[n2][n1] = 1;
        }
        countZeroTo(n);
        cout << result << "\n";
    }
}