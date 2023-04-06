#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> picked;
bool is_used[9];
int domain_[9];
vector<int> chosen;

void permutation_with_repeat(int n,int m){
    if(chosen.size() == m){
        for(int i: chosen)
            cout << domain_[i-1] << " ";
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
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        domain_[i] = temp;
        }
    sort(domain_, domain_+N);
    permutation_with_repeat(N, M); 
    return 0;
}