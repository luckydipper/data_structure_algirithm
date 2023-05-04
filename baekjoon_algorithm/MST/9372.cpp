#include <bits/stdc++.h>
using namespace std;
int T, M, N;
vector<pair<int, pair<int, int>>> edges;


struct DISJOINT_SET{
    vector<int> parent; //1~n
    DISJOINT_SET() = default;
    int find(int sibling){
        if(sibling == parent[sibling])
            return sibling;
        else 
            return find(parent[sibling]);
    } 
    void merge(int a, int b){
        int root_a = find(a);
        int root_b = find(b);
        if(root_a != root_b)
            parent[root_a] = root_b;
    }
    void remake(int n){
        parent.resize(n+1);
        for(int i = 1; i <= n; i++)
            parent[i] = i;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    DISJOINT_SET ds{};
    while(T--){
        cin >> N >> M;
        int result = 0;
        ds.remake(N);

        while(M--){
            int from, to;
            cin >> from >> to;
            if(ds.find(from) != ds.find(to)){
                ds.merge(from, to);
                result++;
            }
        }
        cout << result << "\n";
        result = 0;
    }
    return 0;
}