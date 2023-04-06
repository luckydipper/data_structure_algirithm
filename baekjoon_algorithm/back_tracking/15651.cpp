#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> chosen;

void permutation_with_repeat(int n,int m){
    if(chosen.size() == m){
        for(int i: chosen)
            cout << i << " ";
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++){
        chosen.push_back(i);
        permutation_with_repeat(n, m);
        chosen.pop_back();
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    permutation_with_repeat(N, M);
    return 0;
}