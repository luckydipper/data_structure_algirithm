#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> picked;
bool is_used[9];
int domain_[9];
vector<int> chosen;

void Homogenious(int n, int m){
    if(chosen.size() == m){
        for(int i: chosen)
            cout << domain_[i] << " ";
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
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        domain_[i] = temp;
        }
    sort(domain_, domain_+N);
    Homogenious(N, M); 
    return 0;
}