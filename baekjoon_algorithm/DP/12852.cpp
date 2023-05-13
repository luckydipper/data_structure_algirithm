#include<bits/stdc++.h>
using namespace std;

int X, result;
int cache[1000001];
int parent[1000001];

void print_parent(int from){
    cout << from << " ";
    if(from == 1)
        return;
    print_parent(parent[from]);
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> X;
    for(int i = 1; i <= X; i++){
        parent[i] = i;
        cache[i] = -1;
    }
    cache[1] = parent[1] = 0;
    cache[2] = parent[2] = 1;
    cache[3] = parent[3] = 1;
    
    for(int i = 4; i <= X; i++){
        int min = cache[i-1];
        parent[i] = i-1;
        if(i%3 == 0 && cache[i/3] < min){
            min = cache[i/3];
            parent[i] = i/3;
        
        }
        if(i%2 == 0 && cache[i/2] < min){
            min = cache[i/2];
            parent[i] = i/2;
        }
        cache[i] = min + 1;
    }
    cout << cache[X] << "\n";
    print_parent(X);
}