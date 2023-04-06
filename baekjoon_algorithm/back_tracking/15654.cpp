#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> picked;
bool is_used[9];
int domain_[9];

// nCm
void print_combination(int n, int m){
    if(picked.size() == m){
        for(int elem: picked)
            cout << domain_[elem-1] << " ";
        cout << "\n";
        return;
    }
    
    // 내림 차순 정렬 후, 안 쓰는 smallest indx 반환하는 것이 중요.
    int smallest = picked.empty() ? 1 : picked.back()+1;
    
    //smalllest부터 돌음
    for(int i = smallest; i <= n; i++){
        picked.push_back(i); 
        print_combination(n, m); 
        picked.pop_back();
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
    print_combination(N, M); 
    return 0;
}