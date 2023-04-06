#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> picked;
bool is_used[9];
int domain_[9];
// nPm
void print_permutaion(int n, int m){
    if(picked.size() == m){
        for(int elem: picked)
            cout << domain_[elem-1] << " ";
        cout << "\n";
        return;
    }
    
    for(int i = 1; i <= n; i++){
        if(is_used[i]) continue;
        is_used[i] = true;
        picked.push_back(i); // 이걸 넣으니 homobgenious가 됨.
        print_permutaion(n, m); // print_permutaion(i, m) 
        is_used[i] = false;
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
    print_permutaion(N, M); 
    return 0;
}