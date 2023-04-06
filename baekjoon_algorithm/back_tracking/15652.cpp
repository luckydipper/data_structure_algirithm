#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> chosen;

void Homogenious(int n, int m){
    if(chosen.size() == m){
        for(int i: chosen)
            cout << i+1 << " ";
        cout << "\n";
        return;
    }
    int smallest = chosen.empty() ? 0 : chosen.back();
    for(int i = smallest; i < n; i++){
        chosen.push_back(i);
        Homogenious(n, m);
        chosen.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    Homogenious(N, M);
    return 0;
}